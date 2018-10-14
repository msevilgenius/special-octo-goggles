#include "faces/roomba/dead.h"


namespace faces{
namespace roomba{

using namespace faces::roomba;
using rgb_matrix::Color;

Dead::Dead(Color color) : _color(color)
{

}


Dead::Render(FrameCanvas* canvas)
{
            // draw left x
            DrawLine(offscreen, 4, 5, 10, 11, _color);
            DrawLine(offscreen, 4, 6,  9, 11, _color);
            DrawLine(offscreen, 5, 5, 10, 10, _color);
            // draw left x /
            DrawLine(offscreen, 4, 10,  9, 5, _color);
            DrawLine(offscreen, 4, 11, 10, 5, _color);
            DrawLine(offscreen, 5, 11, 10, 6, _color);
            // draw right x
            DrawLine(offscreen, 21, 5, 27, 11, _color);
            DrawLine(offscreen, 21, 6, 26, 11, _color);
            DrawLine(offscreen, 22, 5, 27, 10, _color);
            // draw right x /
            DrawLine(offscreen, 21, 10, 26, 5, _color);
            DrawLine(offscreen, 21, 11, 27, 5, _color);
            DrawLine(offscreen, 22, 11, 27, 6, _color);
}

}
}