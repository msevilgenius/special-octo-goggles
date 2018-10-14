#pragma once

#include "../faces.h"

#include "led-matrix.h"
#include "graphics.h"
#include "../../drawing.h"

using rgb_matrix::Color;

namespace faces{
namespace roomba{

class Dead : public IFaceState {
    public:
        Dead(Color color);
        void Render(rgb_matrix::FrameCanvas* canvas);
    private:
        Color _color;
};

}
}