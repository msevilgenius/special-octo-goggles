#include "faces/roomba/happy.h"

using namespace faces::roomba;
using rgb_matrix::Color;

Happy::Happy(Color color) : _color(color)
{

}


Happy::Render(FrameCanvas* canvas)
{
    // draw left ^
    DrawLine(offscreen, 3, 7, 7, 3, _color);
    DrawLine(offscreen, 3, 8, 7, 4, _color);
    DrawLine(offscreen, 4, 8, 7, 5, _color);
    DrawLine(offscreen, 8, 4, 11, 7, _color);
    DrawLine(offscreen, 8, 5, 11, 8, _color);
    DrawLine(offscreen, 8, 6, 10, 8, _color);
    // draw right ^
    DrawLine(offscreen, 20, 7, 24, 3, _color);
    DrawLine(offscreen, 20, 8, 24, 4, _color);
    DrawLine(offscreen, 21, 8, 24, 5, _color);
    DrawLine(offscreen, 25, 4, 28, 7, _color);
    DrawLine(offscreen, 25, 5, 28, 8, _color);
    DrawLine(offscreen, 25, 6, 27, 8, _color);
}