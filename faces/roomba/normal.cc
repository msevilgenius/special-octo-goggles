#include "normal.h"


namespace faces{
namespace roomba{

using namespace faces::roomba;
using rgb_matrix::FrameCanvas;

Normal::Normal(Color color) : _color(color)
{

}


void Normal::Render(FrameCanvas* canvas)
{
    drawing::DrawRect(canvas, 6 + x, 5 + y, 3, 6, _color);
    canvas->SetPixel( 7 + x,  4 + y, _color.r, _color.g, _color.b);
    canvas->SetPixel( 7 + x, 11 + y, _color.r, _color.g, _color.b);
    drawing::DrawRect(canvas, 23 + x, 5 + y, 3, 6, _color);
    canvas->SetPixel(24 + x,  4 + y, _color.r, _color.g, _color.b);
    canvas->SetPixel(24 + x, 11 + y, _color.r, _color.g, _color.b);
}

}
}