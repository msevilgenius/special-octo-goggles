#pragma once

#include "led-matrix.h"

#include "SDL2/SDL.h"

namespace faces{

class IFace {
    public:
        virtual ~IFace() {}
        virtual void Start() {}
        virtual void Update(const Uint32 time) {}
        virtual void OnEvent(SDL_Event* event) {}
};

class IFaceState {
    public:
        virtual void Render(rgb_matrix::FrameCanvas* canvas) {}
};


}