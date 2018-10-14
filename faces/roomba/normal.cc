#include "faces/roomba/normal.h"


namespace faces{
namespace roomba{

using namespace faces::roomba;

Normal::Normal(Color color) : _color(color)
{

}


Normal::Render(FrameCanvas* canvas)
{
    DrawRect(offscreen, 6, 5, 3, 6, _color)
    offscreen->SetPixel( 7,  4, _color.r, _color.g, _color.b);
    offscreen->SetPixel( 7, 11, _color.r, _color.g, _color.b);
    DrawRect(offscreen, 23, 5, 3, 6, _color)
    offscreen->SetPixel(24,  4, _color.r, _color.g, _color.b);
    offscreen->SetPixel(24, 11, _color.r, _color.g, _color.b);
}

}
}