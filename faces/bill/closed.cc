#include "closed.h"


namespace faces{
namespace bill{

using namespace faces::bill;
using rgb_matrix::FrameCanvas;

Closed::Closed(Color color) : _color(color)
{

}


void Closed::Render(FrameCanvas* canvas)
{
    drawing::DrawRect(canvas, 5 + x, 8 + y, 7, 1, _color);
    drawing::DrawRect(canvas, 20 + x, 8 + y, 7, 1, _color);
}

}
}