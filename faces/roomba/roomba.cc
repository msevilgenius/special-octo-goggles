#include "roomba.h"

#include <iostream>

namespace faces{

using namespace rgb_matrix;
using rgb_matrix::RGBMatrix;
using rgb_matrix::FrameCanvas;

Roomba::Roomba(RGBMatrix *matrix, SDL_Joystick* js) : matrix(matrix), state(normal), normal_face(roomba::Normal(color)), closed_face(roomba::Closed(color)),
                                    happy_face(roomba::Happy(color)), dead_face(roomba::Dead(color)), lewded_face(roomba::Lewded(color)),
                                    current_face(&normal_face), joystick(js)
{
    offscreen = matrix->CreateFrameCanvas();
}


Roomba::~Roomba()
{
    // offscreen is owned by the matrix
}


void Roomba::Start()
{
    state_change_time = (rand() % 100 + 2) * 100;
    state = normal;
    state_timer = 0;
}

void Roomba::OnEvent(SDL_Event* event)
{
    switch(event->type) {
        case SDL_CONTROLLERAXISMOTION:
        case SDL_JOYAXISMOTION:
            break;
        case SDL_JOYBUTTONDOWN:
            switch (event->jbutton.button) {
                case 0:
                    if (state == happy) {
                        state = normal;
                        current_face = &normal_face;
                        state_timer = 0;
                        state_change_time = (rand() % 100 + 2) * 100;
                        break;
                    }
                    state = happy;
                    current_face = &happy_face;
                    break;
                case 1:
                    if (state == lewded) {
                        state = normal;
                        current_face = &normal_face;
                        state_timer = 0;
                        state_change_time = (rand() % 100 + 2) * 100;
                        break;
                    }
                    state = lewded;
                    current_face = &lewded_face;
                    break;
                case 2:
                    if (state == dead) {
                        state = normal;
                        current_face = &normal_face;
                        state_timer = 0;
                        state_change_time = (rand() % 100 + 2) * 100;
                        break;
                    }
                    state = dead;
                    current_face = &dead_face;
                    break;
                case 3:
                    break;
                case 4:
                    break;
            }
            //std::cout << "button down\n";
            break;
        case SDL_JOYBUTTONUP:
            //std::cout << "button up\n";
            break;
    }
}


void Roomba::Update(const Uint32 frameTime)
{
    DoStateUpdate(frameTime);
    offscreen->Clear();
    current_face->Render(offscreen);
    offscreen = matrix->SwapOnVSync(offscreen);
}

void Roomba::DoStateUpdate(const Uint32 frameTime)
{
    Sint16 xAxis = SDL_JoystickGetAxis(joystick, 0);
    Sint16 yAxis = SDL_JoystickGetAxis(joystick, 1);

    int xEye = xAxis / 8192;
    int yEye = yAxis / 8192;

    switch (state){
        case normal:
            state_timer += frameTime;
            if (state_timer >= state_change_time) {
                state = blink;
                current_face = &closed_face;
                state_timer -= state_change_time;
                state_change_time = 250;
            }
            break;
        case blink:
            state_timer += frameTime;
            if (state_timer >= state_change_time){
                state = normal;
                current_face = &normal_face;
                state_timer -= state_change_time;
                state_change_time = (rand() % 100 + 2) * 100;
            }
            break;
        case happy:
        case dead:
        case lewded:
            break;
    }
    current_face->SetPosition(-xEye, yEye);
}

}
