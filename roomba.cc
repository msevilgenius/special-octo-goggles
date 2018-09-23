#include "roomba.h"

using namespace rgb_matrix;

Roomba::Roomba(RGBMatrix *matrix) : matrix(matrix), state(normal)
{

}


Roomba::~Roomba()
{

}


Roomba::Start()
{
    FrameCanvas *offscreen = matrix->CreateFrameCanvas();





    offscreen = matrix->SwapOnVSync(offscreen);
}