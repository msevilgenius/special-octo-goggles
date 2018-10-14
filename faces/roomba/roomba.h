#pragma once

#include "faces/roomba/normal.h"
#include "faces/roomba/closed.h"
#include "faces/roomba/happy.h"
#include "faces/roomba/dead.h"
#include "faces/roomba/lewded.h"

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

        IFaceState* current_face;
        Roomba::Normal normal_face;
        Roomba::Closed closed_face;
        Roomba::Happy happy_face;
        Roomba::Dead dead_face;
        Roomba::Lewded lewded_face;
};

enum RoombaState{
    normal,
    blink,
    happy,
    dead,
    lewded,
};


}