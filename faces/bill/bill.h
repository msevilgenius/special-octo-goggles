#pragma once

#include "normal.h"
#include "closed.h"
#include "brows.h"
#include "quizical.h"
#include "angry.h"

#include "../faces.h"
#include "led-matrix.h"
#include "graphics.h"
#include "../../drawing.h"

using rgb_matrix::Color;
using rgb_matrix::RGBMatrix;
using rgb_matrix::FrameCanvas;

namespace faces{

enum BillState{
    normal,
    blink,
    closed,
    brows,
    quizical,
    angry,
};

class Bill : public IFace {
    public:
        Bill(RGBMatrix* matrix, SDL_Joystick* js);
        ~Bill();
        void Start();
        void Update(const Uint32 time);
        void OnEvent(SDL_Event* event);
    private:
        RGBMatrix *matrix;
        FrameCanvas *offscreen;
        BillState state;
        const Color color = Color(85, 210, 95);
        Uint32 state_timer;
        Uint32 state_change_time;

        SDL_Joystick* joystick;

        void DoStateUpdate(Uint32 time);

        IFaceState* current_face;
        bill::Normal normal_face;
        bill::Closed closed_face;
        bill::Brows brows_face;
        bill::Quizical quizical_face;
        bill::Angry lewded_face;
};


}