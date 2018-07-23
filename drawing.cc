#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include "drawing.h"

namespace drawing{


void DrawRect(Canvas *c, int x, int y, int w, int h, const Color &color) {
    assert(w > 0);
    assert(h > 0);
    for (auto i = 0; i < w; ++i) {
        for (auto j = 0; j < h; ++j) {
            c->SetPixel(x + i - (w/2), y + j - (h/2), color.r, color.g, color.b);
        }
    }
}

// this may draw poor lines
void DrawLineDDA(Canvas *c, int x1, int y1, int x2, int y2, const Color &color) {
    auto len = abs(x1 - x2) >= abs(y1 - y2) ? abs(x1 - x2) : abs(y1 - y2);

    auto dx = (x1 - x2) / len;
    auto dy = (y1 - y2) / len;

    float x = x1;
    float y = y1;

    for (auto i = 0; i < len; ++i) {
        c->SetPixel(x, y, color.r, color.g, color.b);
        x += dx;
        y += dy;
    }
}

void DrawLineBresenham(Canvas *c, int x1, int y1, int x2, int y2, const Color &color) {
    int a1, a2, b1, b2;

    if (abs(x2 - x1) > abs(y2 - y1)) {
        a1 = x1;
        a2 = x2;
        b1 = y1;
        b2 = y2;
    } else {
        a1 = y1;
        a2 = y2;
        b1 = x1;
        b2 = x2;
    }

    auto a = a1;
    auto b = b1;

    auto da = abs(a2 - a1);
    auto db = abs(b2 - b1);

    float e = 2 * db - da;
    for (auto i = 0; i < da; ++i) {
        c->SetPixel(a, b, color.r, color.g, color.b);
        while (e >= 0) {
            b += b1 > b2 ? -1 : 1; // place this algorith show just b++ is this right?
            e -= 2 * da;
        }
        a += a1 > a2 ? -1 : 1;
        e += 2 * db;
    }
}

void DrawLineBresenham_shallow_ltr(Canvas *c, int x1, int y1, int x2, int y2, const Color &color) {
    auto x = x1;
    auto y = y1;

    auto dx = (x2 - x1);
    auto dy = (y2 - y1);

    float e = 2 * dy - dx;
    for (auto i = 1; i <= dx; ++i) {
        c->SetPixel(x, y, color.r, color.g, color.b);
        while (e >= 0) {
            ++y;
            e -= 2 * dx;
        }
        ++x;
        e += 2 * dy;
    }
}

void DrawFlatTopTriangle(Canvas *c, Point p1, Point p2, Point p3, const Color &color) {
    assert(p1.y == p2.y);
    float gl, gr;
    float xl, xr;

    if (p1.x < p2.x) {
        gl = (p3.x - p1.x) / (p2.y - p1.y);
        gr = (p3.x - p2.x) / (p3.y - p2.y);
    } else {
        gl = (p3.x - p2.x) / (p3.y - p2.y);
        gr = (p3.x - p1.x) / (p2.y - p1.y);
    }

    xl = p1.x;
    xr = p1.x;

    for (int y = p2.y; y > p1.y; --y) {
        for (int x = xl; x <= xr; ++x) {
            c->SetPixel(x, y, color.r, color.g, color.b);
        }
        xl -= gl;
        xr -= gr;
    }
}

void DrawFlatBottomTriangle(Canvas *c, Point p1, Point p2, Point p3, const Color &color) {
    assert(p2.y == p3.y);
    float gl, gr;
    float xl, xr;

    if (p2.x < p3.x) {
        gl = (p2.x - p1.x) / (p2.y - p1.y);
        gr = (p3.x - p1.x) / (p3.y - p1.y);
    } else {
        gl = (p3.x - p1.x) / (p3.y - p1.y);
        gr = (p2.x - p1.x) / (p2.y - p1.y);
    }

    xl = p1.x;
    xr = p1.x;

    for (int y = p1.y; y <= p2.y; ++y) {
        for (int x = xl; x <= xr; ++x) {
            c->SetPixel(x, y, color.r, color.g, color.b);
        }
        xl += gl;
        xr += gr;
    }
}

void DrawTriangle(Canvas *c, Point p1, Point p2, Point p3, const Color &color) {
    Point verts[3] = {p1, p2, p3};
    // sort verts by Y ascending
    if (verts[0].y > verts[1].y) {
        auto tmp = verts[0];
        verts[0] = verts[1];
        verts[1] = tmp;
    }
    if (verts[1].y > verts[2].y) {
        auto tmp = verts[1];
        verts[1] = verts[2];
        verts[2] = tmp;
    }
    if (verts[0].y > verts[1].y) {
        auto tmp = verts[0];
        verts[0] = verts[1];
        verts[1] = tmp;
    }

    if (verts[1].y == verts[2].y) { // flat bottom triangle
        DrawFlatBottomTriangle(c, verts[0], verts[1], verts[2], color);
    }
    else if (verts[0].y == verts[1].y) { // flat top triangle
        DrawFlatTopTriangle(c, verts[0], verts[1], verts[2], color);
    }
    else { // split into a flat top and flat bottomed triangle
        Point p4(verts[0].x + ((verts[1].y - verts[0].y)/(verts[2].y - verts[0].y)) * (verts[2].x - verts[0].x), verts[1].y);
        DrawFlatBottomTriangle(c, verts[0], verts[1], p4, color);
        DrawFlatTopTriangle(c, verts[1], p4, verts[2], color);
    }
}

// find which side of a line a given point is on
// returns 0 if p is on the line v0 -> v1
// returns a positive value if v0 -> v1 -> p forms a clockwise triangle, negative if anticlockwise
int EdgeFunction(Point v0, Point v1, Point p) {
    return (p.x - v0.x) * (v0.y - v1.y) - (p.y - v0.y) * (v0.x - v1.x);
}

// rotates a point about 0,0; angle in degrees
Point RotatePoint(Point p, float angle) {
    const float PI = 3.14159265;
    int x, y;
    auto theta = angle * PI / 180;
    auto sint = sin(theta);
    auto cost = cos(theta);
    x = p.x * cost + p.y * -sint;
    y = p.x * sint + p.y * cost;
    return Point(x, y);
}

void DrawRectRot(Canvas *c, int x, int y, int w, int h, float angle, const Color &color) {
    Point p[4] = { Point(-w/2, -h/2), Point(w/2, -h/2), Point(-w/2, h/2), Point(w/2 , h/2) };
    Point translate(x, y);
    for (auto i = 0; i < 4; ++i) {
        p[i] = RotatePoint(p[i], angle) + translate;
    }
    DrawTriangle(c, p[0], p[1], p[2], color);
    DrawTriangle(c, p[1], p[2], p[3], color);
}


} //namespace