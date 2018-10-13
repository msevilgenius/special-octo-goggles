#pragma once

#include "faces/faces.h"

#include "graphics.h"

using rgb_matrix::Color;

namespace faces{
namespace roomba{

class Happy : public IFaceState {
    public:
        Happy(Color color)
    private:
        Color _color;
};

}
}