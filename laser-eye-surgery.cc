#include "led-matrix.h"
#include "drawing.h"

#include <unistd.h>
#include <math.h>
#include <stdio.h>
#include <signal.h>

using rgb_matrix::GPIO;
using rgb_matrix::RGBMatrix;
using rgb_matrix::Canvas;



volatile bool interrupt_received = false;
static void InterruptHandler(int signo) {
  interrupt_received = true;
}

int main(int argc, char *argv[]) {

    RGBMatrix::Options defaults;
    defaults.hardware_mapping = "regular-pi1";
    defaults.rows = 16;
    defaults.cols = 32;
    defaults.chain_length = 1;
    defaults.parallel = 1;
    defaults.show_refresh_rate = true;
    defaults.disable_hardware_pulsing = true;
    rgb_matrix::RuntimeOptions runtime_opt;

    RGBMatrix *matrix = CreateMatrixFromOptions(defaults, runtime_opt);

    if (matrix == NULL) {
        PrintMatrixFlags(stderr, defaults, runtime_opt);
        return 1;
    }


    // It is always good to set up a signal handler to cleanly exit when we
    // receive a CTRL-C for instance. The DrawOnCanvas() routine is looking
    // for that.
    signal(SIGTERM, InterruptHandler);
    signal(SIGINT, InterruptHandler);

    Canvas *canvas = matrix;

    float angle = 45;
    while(!interrupt_received) {

        drawing::DrawRectRot(canvas, 8, 8, 7, 3, angle, Color(230, 15, 35));
        drawing::DrawRectRot(canvas, 8, 8, 3, 7, angle, Color(230, 15, 35));
        drawing::DrawRectRot(canvas, 24, 8, 7, 3, angle, Color(230, 15, 35));
        drawing::DrawRectRot(canvas, 24, 8, 3, 7, angle, Color(230, 15, 35));
        angle += 90 / 1000;
        usleep(1 * 1000);
    }

    delete matrix;
    return 0;
}