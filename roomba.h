#pragma once

#include "led-matrix.h"
#include "graphics.h"



namespace faces{

class Roomba{
    public:
        Roomba(RGBMatrix *matrix)
        void Start();
        void normal();
        void closed();
        void happy();
        void dead();
        void lewded();
    private:
        RGBMatrix *matrix;
        struct LedCanvas *offscreen_canvas;
        RoombaState state;
};

enum RoombaState{
    normal,
    blink,
    happy,
    dead,
    lewded,
}


}