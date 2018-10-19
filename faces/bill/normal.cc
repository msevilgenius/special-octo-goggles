#include "normal.h"


namespace faces{
namespace bill{

using namespace faces::bill;
using rgb_matrix::FrameCanvas;

Normal::Normal(Color color) : _color(color)
{

}


void Normal::Render(FrameCanvas* canvas)
{
    drawing::DrawRect(canvas, 6 + x, 7 + y, 5, 5, _color);
    drawing::DrawRect(canvas, 21 + x, 7 + y, 5, 5, _color);
}

}
}