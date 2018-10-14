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
    DrawRect(canvas, 6, 5, 3, 6, _color)
    canvas->SetPixel( 7,  4, _color.r, _color.g, _color.b);
    canvas->SetPixel( 7, 11, _color.r, _color.g, _color.b);
    DrawRect(canvas, 23, 5, 3, 6, _color)
    canvas->SetPixel(24,  4, _color.r, _color.g, _color.b);
    canvas->SetPixel(24, 11, _color.r, _color.g, _color.b);
}

}
}