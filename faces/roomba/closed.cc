#include "closed.h"

namespace faces{
namespace roomba{


using namespace faces::roomba;
using rgb_matrix::Color;
using rgb_matrix::FrameCanvas;

Closed::Closed(Color color) : _color(color)
{

}


void Closed::Render(FrameCanvas* canvas)
{
    drawing::DrawRect(canvas,  3, 8, 9, 2, _color);
    drawing::DrawRect(canvas, 20, 8, 9, 2, _color);
}

}
}