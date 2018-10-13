#include "faces/roomba/closed.h"

using namespace faces::roomba;
using rgb_matrix::Color;

Closed::Closed(Color color) : _color(color)
{

}


Closed::Render(FrameCanvas* canvas)
{
    DrawRect(offscreen,  3, 8, 9, 2, _color);
    DrawRect(offscreen, 20, 8, 9, 2, _color);
}