#include "roomba.h"

namespace faces{

using namespace rgb_matrix;
using rgb_matrix::RGBMatrix;
using rgb_matrix::FrameCanvas;

Roomba::Roomba(RGBMatrix *matrix) : matrix(matrix), state(normal), normal_face(roomba::Normal(color)), closed_face(roomba::Closed(color)),
                                    happy_face(roomba::Happy(color)), dead_face(roomba::Dead(color)), lewded_face(roomba::Lewded(color)),
                                    current_face(&normal_face), button_down(false)
{
    offscreen = matrix->CreateFrameCanvas();
}


Roomba::~Roomba()
{
    // offscreen is owned by the matrix
}


void Roomba::Start()
{
}

void Roomba::OnEvent(SDL_Event* event)
{
    switch(event->type) {
        case SDL_CONTROLLERAXISMOTION:
        case SDL_JOYAXISMOTION:
            break;
        case SDL_CONTROLLERBUTTONDOWN:
        case SDL_JOYBUTTONDOWN:
        case SDL_KEYDOWN:
            button_down = true;
            break;
        case SDL_CONTROLLERBUTTONUP:
        case SDL_JOYBUTTONUP:
        case SDL_KEYUP:
            button_down = false;
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

    if (!button_down){
        state = dead;
        current_face = &dead_face;
        return;
    }
    switch (state){
        case normal:
            state_timer += frameTime;
            if (state_timer >= state_change_time) {
                state = blink;
                current_face = &closed_face;
                state_timer -= state_change_time;
                state_change_time = 300;
            }
            break;
        case blink:
            state_timer += frameTime;
            if (state_timer >= state_change_time){
                state = normal;
                current_face = &normal_face;
                state_timer -= state_change_time;
                state_change_time = (rand() % 100 + 2) * 100;
                //state_change_time = 10000;
            }
            break;
        case happy:
        case dead:
        case lewded:
            if (!button_down){
                state = normal;
                current_face = &normal_face;
                state_timer -= state_change_time;
                state_change_time = (rand() % 100 + 2) * 100;
                //state_change_time = 10000;
            }
            break;
    }
}

}