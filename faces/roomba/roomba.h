#pragma once

#include "normal.h"
#include "closed.h"
#include "happy.h"
#include "dead.h"
#include "lewded.h"

#include "../faces.h"
#include "led-matrix.h"
#include "graphics.h"
#include "../../drawing.h"

using rgb_matrix::Color;
using rgb_matrix::RGBMatrix;
using rgb_matrix::FrameCanvas;

namespace faces{

enum RoombaState{
    normal,
    blink,
    happy,
    dead,
    lewded,
};

class Roomba : public IFace {
    public:
        Roomba(RGBMatrix* matrix);
    private:
        RGBMatrix *matrix;
        FrameCanvas *offscreen;
        RoombaState state;
        const Color color = Color(255, 0, 148);
        Uint32 state_timer;
        Uint32 state_change_time;

        void DoStateUpdate(Uint32 time);

        IFaceState* current_face;
        roomba::Normal normal_face;
        roomba::Closed closed_face;
        roomba::Happy happy_face;
        roomba::Dead dead_face;
        roomba::Lewded lewded_face;
};


}