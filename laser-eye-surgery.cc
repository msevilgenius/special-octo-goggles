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

void OnEvent(SDL_Event* event) {

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

    RGBMatrix *matrix = CreateMatrixFromOptions(defaults, runtime_opt);

    if (matrix == NULL) {
        PrintMatrixFlags(stderr, defaults, runtime_opt);
        return 1;
    }

    if (SDL_Init(SDL_INIT_TIMER | SDL_INIT_GAMECONTROLLER | SDL_INIT_EVENTS)) {
        delete matrix;
        std::cout << "failed sdl init" << std::endl;
        return 1;
    }





    faces::Roomba face(matrix);

    face.Start();

    while(!interrupt_received) {


        while (SDL_PollEvent(&event)){
            OnEvent(&event);
        }

        currentTime = SDL_GetTicks();
        frameTime = currentTime - lastRenderTime;
        face.Update(frameTime);
        lastRenderTime = currentTime;
    }

    SDL_Quit();
    delete matrix;
    return 0;
}