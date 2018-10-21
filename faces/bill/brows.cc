#include "brows.h"


namespace faces{
namespace bill{

using namespace faces::bill;
using rgb_matrix::FrameCanvas;

Brows::Brows(Color color) : _color(color)
{

}


void Brows::Render(FrameCanvas* canvas)
{
    int ay = y < -3 ? -3 : y;
    drawing::DrawRect(canvas, 4 + (x/4), 3 + ay, 8, 1, _color);
    drawing::DrawRect(canvas, 20 + (x/4), 3 + ay, 8, 1, _color);


    drawing::DrawRect(canvas, 6 + x, 7, 5, 5, _color);
    drawing::DrawRect(canvas, 21 + x, 7, 5, 5, _color);
}

}
}