#include "bill.h"

#include <iostream>

namespace faces{

using namespace rgb_matrix;
using rgb_matrix::RGBMatrix;
using rgb_matrix::FrameCanvas;

Bill::Bill(RGBMatrix *matrix, SDL_Joystick* js) : matrix(matrix), state(normal), normal_face(bill::Normal(color)), closed_face(bill::Closed(color)),
                                    brows_face(bill::Brows(color)), quizical_face(bill::Quizical(color)), angry_face(bill::Angry()),
                                    current_face(&normal_face), joystick(js)
{
    offscreen = matrix->CreateFrameCanvas();
}


Bill::~Bill()
{
    // offscreen is owned by the matrix
}


void Bill::Start()
{
    state_change_time = (rand() % 100 + 2) * 100;
    state = normal;
}

void Bill::OnEvent(SDL_Event* event)
{
    switch(event->type) {
        case SDL_CONTROLLERAXISMOTION:
        case SDL_JOYAXISMOTION:
            break;
        case SDL_CONTROLLERBUTTONDOWN:
        case SDL_JOYBUTTONDOWN:
        case SDL_KEYDOWN:
            std::cout << "button down\n";
            break;
        case SDL_CONTROLLERBUTTONUP:
        case SDL_JOYBUTTONUP:
        case SDL_KEYUP:
            std::cout << "button up\n";
            break;
    }
}


void Bill::Update(const Uint32 frameTime)
{
    DoStateUpdate(frameTime);
    offscreen->Clear();
    current_face->Render(offscreen);
    offscreen = matrix->SwapOnVSync(offscreen);
}

void Bill::DoStateUpdate(const Uint32 frameTime)
{
    Sint16 xAxis = SDL_JoystickGetAxis(joystick, 0);
    Sint16 yAxis = SDL_JoystickGetAxis(joystick, 1);

    int xEye = xAxis / 8192;
    int yEye = yAxis / 8192;

    switch (state){
        case normal:
            state_timer += frameTime;
            if (state_timer >= state_change_time) {
                std::cout << "blinking\n";
                state = blink;
                current_face = &closed_face;
                state_timer -= state_change_time;
                state_change_time = 300;
            }
            break;
        case blink:
            state_timer += frameTime;
            if (state_timer >= state_change_time){
                std::cout << "stopped blinking\n";
                state = normal;
                current_face = &normal_face;
                state_timer -= state_change_time;
                //state_change_time = (rand() % 100 + 2) * 100;
                state_change_time = 10000;
            }
            break;
        case closed:
        case brows:
        case quizical:
        case angry:
            break;
    }
    current_face->SetPosition(-xEye, yEye);
}

}