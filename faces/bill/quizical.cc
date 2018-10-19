#include "quizical.h"


namespace faces{
namespace bill{

using namespace faces::bill;
using rgb_matrix::FrameCanvas;

Quizical::Quizical(Color color) : _color(color)
{

}


void Quizical::Render(FrameCanvas* canvas)
{
    DrawLine(canvas, 4 + (x/4), 5 + (y/4), 11 + (x/4), 4 + (y/4), _color);
    DrawLine(canvas, 20 + (x/4), 1 + (y/4), 27 + (x/4), 2 + (y/4), _color);

    drawing::DrawRect(canvas, 6 + x, 8 + (y/2), 5, 5, _color);
    drawing::DrawRect(canvas, 21 + x, 8 + (y/2), 5, 5, _color);
}

}
}