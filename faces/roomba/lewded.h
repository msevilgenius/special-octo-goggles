#pragma once

#include "../faces.h"

#include "led-matrix.h"
#include "graphics.h"
#include "../../drawing.h"

using rgb_matrix::Color;

namespace faces{
namespace roomba{

class Lewded : public IFaceState {
    public:
        Lewded(Color color);
        void Render(rgb_matrix::FrameCanvas* canvas);
    private:
        Color _color;
};

}
}