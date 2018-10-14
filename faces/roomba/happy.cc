#include "happy.h"


namespace faces{
namespace roomba{

using namespace faces::roomba;
using rgb_matrix::Color;
using rgb_matrix::FrameCanvas;

Happy::Happy(Color color) : _color(color)
{

}


void Happy::Render(FrameCanvas* canvas)
{
    // draw left ^
    DrawLine(canvas, 3, 7, 7, 3, _color);
    DrawLine(canvas, 3, 8, 7, 4, _color);
    DrawLine(canvas, 4, 8, 7, 5, _color);
    DrawLine(canvas, 8, 4, 11, 7, _color);
    DrawLine(canvas, 8, 5, 11, 8, _color);
    DrawLine(canvas, 8, 6, 10, 8, _color);
    // draw right ^
    DrawLine(canvas, 20, 7, 24, 3, _color);
    DrawLine(canvas, 20, 8, 24, 4, _color);
    DrawLine(canvas, 21, 8, 24, 5, _color);
    DrawLine(canvas, 25, 4, 28, 7, _color);
    DrawLine(canvas, 25, 5, 28, 8, _color);
    DrawLine(canvas, 25, 6, 27, 8, _color);
}

}
}