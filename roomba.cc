#include "roomba.h"

using namespace rgb_matrix;

Roomba::Roomba(RGBMatrix *matrix) : matrix(matrix), state(normal)
{
    offscreen = matrix->CreateFrameCanvas();
}


Roomba::~Roomba()
{
    delete offscreen;
}


Roomba::Start()
{
}


void Roomba::Update(*events, const Uint32 time)
{
    state = DoStateUpdate(*events, Uint32 time, state)
    offscreen = matrix->SwapOnVSync(offscreen);
}

void Roomba::DoStateUpdate(*events, const Uint32 time)
{
    switch (state){
        case normal:
            // draw normal
            DrawRect(offscreen, 6, 5, 3, 6, color)
            c->SetPixel( 7,  4, color.r, color.g, color.b);
            c->SetPixel( 7, 11, color.r, color.g, color.b);
            DrawRect(offscreen, 23, 5, 3, 6, color)
            c->SetPixel(24,  4, color.r, color.g, color.b);
            c->SetPixel(24, 11, color.r, color.g, color.b);
            // calculate next state
            if (state_timer - time <= 0){
                state = blink;
                state_timer = 400;
            }
            break;
        case blink:
            // draw normal
            DrawRect(offscreen,  3, 8, 9, 2, color)
            DrawRect(offscreen, 20, 8, 9, 2, color)
            // calculate next state
            if (state_timer - time <= 0){
                state = blink;
                state_timer = (rand() % 100 + 2) * 100;
            }
            break;
        case happy:
            // draw left ^
            DrawLine(offscreen, 3, 7, 7, 3, color)
            DrawLine(offscreen, 3, 8, 7, 4, color)
            DrawLine(offscreen, 4, 8, 7, 5, color)
            DrawLine(offscreen, 8, 4, 11, 7, color)
            DrawLine(offscreen, 8, 5, 11, 8, color)
            DrawLine(offscreen, 8, 6, 10, 8, color)
            // draw right ^
            DrawLine(offscreen, 20, 7, 24, 3, color)
            DrawLine(offscreen, 20, 8, 24, 4, color)
            DrawLine(offscreen, 21, 8, 24, 5, color)
            DrawLine(offscreen, 25, 4, 28, 7, color)
            DrawLine(offscreen, 25, 5, 28, 8, color)
            DrawLine(offscreen, 25, 6, 27, 8, color)
            break;
        case dead:
            // draw left x
            DrawLine(offscreen, 4, 5, 10, 11, color)
            DrawLine(offscreen, 4, 6,  9, 11, color)
            DrawLine(offscreen, 5, 5, 10, 10, color)
            // draw left x /
            DrawLine(offscreen, 4, 10,  9, 5, color)
            DrawLine(offscreen, 4, 11, 10, 5, color)
            DrawLine(offscreen, 5, 11, 10, 6, color)
            // draw right x
            DrawLine(offscreen, 21, 5, 27, 11, color)
            DrawLine(offscreen, 21, 6, 26, 11, color)
            DrawLine(offscreen, 22, 5, 27, 10, color)
            // draw right x /
            DrawLine(offscreen, 21, 10, 26, 5, color)
            DrawLine(offscreen, 21, 11, 27, 5, color)
            DrawLine(offscreen, 22, 11, 27, 6, color)
            break;
        case lewded:
            // draw left >
            DrawLine(offscreen, 5, 4,  8, 7, color)
            DrawLine(offscreen, 6, 4,  9, 7, color)
            DrawLine(offscreen, 7, 4, 10, 7, color)
            // draw left > /
            DrawLine(offscreen, 5, 11,  8, 8, color)
            DrawLine(offscreen, 6, 11,  9, 8, color)
            DrawLine(offscreen, 7, 11, 10, 8, color)
            // draw right < /
            DrawLine(offscreen, 24, 4, 21, 7, color)
            DrawLine(offscreen, 25, 4, 22, 7, color)
            DrawLine(offscreen, 26, 4, 23, 7, color)
            // draw right <
            DrawLine(offscreen, 24, 11, 21, 8, color)
            DrawLine(offscreen, 25, 11, 22, 8, color)
            DrawLine(offscreen, 26, 11, 23, 8, color)
            break;

    }
}