#include "lewded.h"

namespace faces{
namespace roomba{

using namespace faces::roomba;
using rgb_matrix::Color;
using rgb_matrix::FrameCanvas;

Lewded::Lewded(Color color) : _color(color)
{

}


void Lewded::Render(FrameCanvas* canvas)
{
    // draw left >
    DrawLine(canvas, 5, 4,  8, 7, _color);
    DrawLine(canvas, 6, 4,  9, 7, _color);
    DrawLine(canvas, 7, 4, 10, 7, _color);
    // draw left > /
    DrawLine(canvas, 5, 11,  8, 8, _color);
    DrawLine(canvas, 6, 11,  9, 8, _color);
    DrawLine(canvas, 7, 11, 10, 8, _color);
    // draw right < /
    DrawLine(canvas, 24, 4, 21, 7, _color);
    DrawLine(canvas, 25, 4, 22, 7, _color);
    DrawLine(canvas, 26, 4, 23, 7, _color);
    // draw right <
    DrawLine(canvas, 24, 11, 21, 8, _color);
    DrawLine(canvas, 25, 11, 22, 8, _color);
    DrawLine(canvas, 26, 11, 23, 8, _color);
}

}
}