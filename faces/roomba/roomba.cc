#include "roomba.h"

namespace faces{

using namespace rgb_matrix;
using rgb_matrix::RGBMatrix;
using rgb_matrix::FrameCanvas;

Roomba::Roomba(RGBMatrix *matrix) : matrix(matrix), state(normal), normal_face(roomba::Normal(color)), closed_face(roomba::Closed(color)),
                                    happy_face(roomba::Happy(color)), dead_face(roomba::Dead(color)), lewded_face(roomba::Lewded(color)),
                                    current_face(&normal_face)
{
    offscreen = matrix->CreateFrameCanvas();
}


Roomba::~Roomba()
{
    delete offscreen;
}


void Roomba::Start()
{
}

void Roomba::OnEvent(SDL_Event& event)
{
    switch(event.type) {
        case SDL_CONTROLLERAXISMOTION:
        case SDL_JOYAXISMOTION:
            break;
        case SDL_CONTROLLERBUTTONDOWN:
        case SDL_JOYBUTTONDOWN:
        case SDL_KEYDOWN:
            break;
        case SDL_CONTROLLERBUTTONUP:
        case SDL_JOYBUTTONUP:
        case SDL_KEYUP:
            break;
    }
}


void Roomba::Update(const Uint32 frameTime)
{
    state = DoStateUpdate(Uint32 frameTime, state)

    current_face->Render(offscreen);
    offscreen = matrix->SwapOnVSync(offscreen);
}

void Roomba::DoStateUpdate(const Uint32 frameTime)
{
    switch (state){
        case normal:
            state_timer += frameTime;
            if (state_timer >= state_change_time) {
                state = blink;
                current_face = &closed_face;
                state_timer -= state_change_time;
                state_change_time = 400;
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
}

}