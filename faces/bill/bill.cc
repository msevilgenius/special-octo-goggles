#include "bill.h"

#include <iostream>

namespace faces{

using namespace rgb_matrix;
using rgb_matrix::RGBMatrix;
using rgb_matrix::FrameCanvas;

Bill::Bill(RGBMatrix *matrix, SDL_Joystick* js) : matrix(matrix), state(normalBill), normal_face(bill::Normal(color)), closed_face(bill::Closed(color)),
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
    state = normalBill;
    state_timer = 0;
}

void Bill::OnEvent(SDL_Event* event)
{
    switch(event->type) {
        case SDL_CONTROLLERAXISMOTION:
        case SDL_JOYAXISMOTION:
            break;
        case SDL_JOYBUTTONDOWN:
            switch (event->jbutton.button) {
                case 0:
                    if (state == brows) {
                        state = normalBill;
                        current_face = &normal_face;
                        state_timer = 0;
                        state_change_time = (rand() % 100 + 2) * 100;
                        break;
                    }
                    state = brows;
                    current_face = &brows_face;
                    break;
                case 1:
                    if (state == closed) {
                        state = normalBill;
                        current_face = &normal_face;
                        state_timer = 0;
                        state_change_time = (rand() % 100 + 2) * 100;
                        break;
                    }
                    state = closed;
                    current_face = &closed_face;
                    break;
                case 2:
                    if (state == quizical) {
                        state = normalBill;
                        current_face = &normal_face;
                        state_timer = 0;
                        state_change_time = (rand() % 100 + 2) * 100;
                        break;
                    }
                    state = quizical;
                    current_face = &quizical_face;
                    break;
                case 3:
                    if (state == angry) {
                        state = normalBill;
                        current_face = &normal_face;
                        state_timer = 0;
                        state_change_time = (rand() % 100 + 2) * 100;
                        break;
                    }
                    state = angry;
                    current_face = &angry_face;
                    break;
                case 4:
                    break;
            }
            break;
        case SDL_JOYBUTTONUP:
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

    int xEye = xAxis / 8190;
    int yEye = yAxis / 8190;

    switch (state){
        case normalBill:
            state_timer += frameTime;
            if (state_timer >= state_change_time) {
                state = blinkBill;
                current_face = &closed_face;
                state_timer -= state_change_time;
                state_change_time = 250;
            }
            break;
        case blinkBill:
            state_timer += frameTime;
            if (state_timer >= state_change_time){
                state = normalBill;
                current_face = &normal_face;
                state_timer -= state_change_time;
                state_change_time = (rand() % 100 + 2) * 100;
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
