#include "faces/faces.h"
#include "faces/roomba/roomba.h"

#include "led-matrix.h"
#include "drawing.h"

#include "SDL2/SDL.h"

#include <unistd.h>
#include <math.h>
#include <stdio.h>
#include <signal.h>
#include <iostream>

using rgb_matrix::GPIO;
using rgb_matrix::RGBMatrix;
using rgb_matrix::Canvas;



volatile bool interrupt_received = false;
static void InterruptHandler(int signo) {
  interrupt_received = true;
}

void OnEvent(SDL_Event* event, faces::IFace* face) {
    face->OnEvent(event);
}

int main(int argc, char *argv[]) {

    RGBMatrix::Options defaults;
    defaults.hardware_mapping = "regular-pi1";
    defaults.rows = 16;
    defaults.cols = 32;
    defaults.chain_length = 1;
    defaults.parallel = 1;
    defaults.show_refresh_rate = true;
    defaults.disable_hardware_pulsing = true;
    rgb_matrix::RuntimeOptions runtime_opt;

    SDL_Event event;
    Uint32 currentTime = 0;
    Uint32 lastRenderTime = 0;
    Uint32 frameTime = 0;

    // It is always good to set up a signal handler to cleanly exit when we
    // receive a CTRL-C for instance. The DrawOnCanvas() routine is looking
    // for that.
    signal(SIGTERM, InterruptHandler);
    signal(SIGINT, InterruptHandler);

    if (SDL_Init(SDL_INIT_TIMER | SDL_INIT_JOYSTICK | SDL_INIT_GAMECONTROLLER | SDL_INIT_EVENTS)) {
        std::cout << "failed sdl init" << std::endl;
        return 1;
    }

    SDL_Joystick* joystick;
    joystick = SDL_JoystickOpen(0);
    std::cout << "js0: " << SDL_JoystickNumAxes(joystick) << " axes\n";
    std::cout << "js0: " << SDL_JoystickNumButtons(joystick) << " buttons\n";
    std::cout << "js0 axis0: " << SDL_JoystickGetAxis(joystick, 0) << "\n";

    int SDL_JoystickEventState(SDL_ENABLE);

    RGBMatrix *matrix = CreateMatrixFromOptions(defaults, runtime_opt);

    if (matrix == NULL) {
        PrintMatrixFlags(stderr, defaults, runtime_opt);
        SDL_Quit();
        return 1;
    }

    faces::Roomba face(matrix, joystick);

    face.Start();

    while(!interrupt_received) {

        SDL_JoystickUpdate();

        while (SDL_PollEvent(&event)){
            OnEvent(&event, &face);
        }

        currentTime = SDL_GetTicks();
        frameTime = currentTime - lastRenderTime;
        face.Update(frameTime);
        lastRenderTime = currentTime;
    }
    SDL_JoystickClose(joystick);

    SDL_Quit();
    delete matrix;
    return 0;
}