#include "angry.h"


namespace faces{
namespace bill{

using namespace faces::bill;
using rgb_matrix::FrameCanvas;

Angry::Angry()
{

}


void Angry::Render(FrameCanvas* canvas)
{
    DrawLine(canvas,  2,  3,  3,  3, _color);
    DrawLine(canvas,  2,  4,  4,  4, _color);
    DrawLine(canvas,  3,  5,  6,  5, _color);
    DrawLine(canvas,  4,  6,  8,  6, _color);
    DrawLine(canvas,  5,  7,  9,  7, _color);
    DrawLine(canvas,  6,  8, 10,  8, _color);
    DrawLine(canvas,  7,  9, 11,  9, _color);
    DrawLine(canvas,  9, 10, 12, 10, _color);
    DrawLine(canvas, 11, 11, 12, 11, _color);

    DrawLine(canvas, 29,  3, 28,  3, _color);
    DrawLine(canvas, 29,  4, 27,  4, _color);
    DrawLine(canvas, 28,  5, 25,  5, _color);
    DrawLine(canvas, 27,  6, 23,  6, _color);
    DrawLine(canvas, 26,  7, 22,  7, _color);
    DrawLine(canvas, 25,  8, 21,  8, _color);
    DrawLine(canvas, 24,  9, 20,  9, _color);
    DrawLine(canvas, 22, 10, 19, 10, _color);
    DrawLine(canvas, 20, 11, 19, 11, _color);
}

}
}
