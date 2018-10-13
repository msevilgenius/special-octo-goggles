#include "faces/roomba/lewded.h"

using namespace faces::roomba;
using rgb_matrix::Color;

Lewded::Lewded(Color color) : _color(color)
{

}


Lewded::Render(FrameCanvas* canvas)
{
    // draw left >
    DrawLine(offscreen, 5, 4,  8, 7, _color);
    DrawLine(offscreen, 6, 4,  9, 7, _color);
    DrawLine(offscreen, 7, 4, 10, 7, _color);
    // draw left > /
    DrawLine(offscreen, 5, 11,  8, 8, _color);
    DrawLine(offscreen, 6, 11,  9, 8, _color);
    DrawLine(offscreen, 7, 11, 10, 8, _color);
    // draw right < /
    DrawLine(offscreen, 24, 4, 21, 7, _color);
    DrawLine(offscreen, 25, 4, 22, 7, _color);
    DrawLine(offscreen, 26, 4, 23, 7, _color);
    // draw right <
    DrawLine(offscreen, 24, 11, 21, 8, _color);
    DrawLine(offscreen, 25, 11, 22, 8, _color);
    DrawLine(offscreen, 26, 11, 23, 8, _color);
}