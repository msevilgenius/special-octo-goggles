#pragma once

#include "faces/faces.h"
#include "led-matrix.h"
#include "graphics.h"
#include "drawing.h"

using rgb_matrix::Color;

namespace faces{

class Roomba : public IFace {
    public:
        Roomba(RGBMatrix *matrix);
    private:
        RGBMatrix *matrix;
        FrameCanvas *offscreen;
        RoombaState state;
        const Color color = Color(256, 0, 148);
        Uint32 state_timer;
        Uint32 state_change_time;

        RoombaState DoStateUpdate(Uint32 time, RoombaState state);
};

enum RoombaState{
    normal,
    blink,
    happy,
    dead,
    lewded,
};


}