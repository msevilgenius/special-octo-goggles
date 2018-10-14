#pragma once

#include "../faces.h"

#include "led-matrix.h"
#include "graphics.h"
#include "../../drawing.h"

using rgb_matrix::Color;

namespace faces{
namespace roomba{

class Happy : public IFaceState {
    public:
        Happy(Color color);
    private:
        Color _color;
};

}
}