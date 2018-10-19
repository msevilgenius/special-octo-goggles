#pragma once

#include "../faces.h"

#include "led-matrix.h"
#include "graphics.h"
#include "../../drawing.h"

using rgb_matrix::Color;

namespace faces{
namespace bill{

class Brows : public IFaceState {
    public:
        Brows(Color color);
        void Render(rgb_matrix::FrameCanvas* canvas);
        void SetPosition(int xEye, int yEye) { x = xEye; y = yEye; }
    private:
        Color _color;
        int x;
        int y;
};

}
}