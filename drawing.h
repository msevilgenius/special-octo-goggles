#pragma once

#include "graphics.h"

using rgb_matrix::Canvas;
using rgb_matrix::Color;

namespace drawing{

struct Point{
    int x;
    int y;
    Point(int _x, int _y) : x(_x), y(_y){}
    Point operator+(const Point &p) {
        return Point(this->x + p.x, this->y + p.y);
    }
};

void DrawRect(Canvas *c, int x, int y, int w, int h, const Color &color);

// this may draw poor lines
void DrawLineDDA(Canvas *c, int x1, int y1, int x2, int y2, const Color &color);

void DrawRectRot(Canvas *c, int x, int y, int w, int h, float angle, const Color &color);

void DrawTriangle(Canvas *c, Point p1, Point p2, Point p3, const Color &color);

} //namespace