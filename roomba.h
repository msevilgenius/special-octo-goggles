#pragma once

#include "led-matrix.h"
#include "graphics.h"
#include "drawing.h"

using rgb_matrix::Color;

namespace faces{

class Roomba : public Face {
    public:
        Roomba(RGBMatrix *matrix)
        void Start();
    private:
        RGBMatrix *matrix;
        FrameCanvas *offscreen;
        RoombaState state;
        const Color color = Color(256, 0, 148);
        Uint32 state_timer;

        RoombaState DoStateUpdate(*events, Uint32 time, RoombaState state);
};

enum RoombaState{
    normal,
    blink,
    happy,
    dead,
    lewded,
}


}