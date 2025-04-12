#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <iostream>

// Function to rotate a point (x, y) around pivot (px, py)
void rotatePoint(int x, int y, int px, int py, float angle, int &xr, int &yr) {
    float rad = angle * M_PI / 180.0;  // Convert to radians

    // Translate point back to origin
    float dx = x - px;
    float dy = y - py;

    // Apply rotation
    xr = px + (dx * cos(rad) - dy * sin(rad));
    yr = py + (dx * sin(rad) + dy * cos(rad));
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    // Original triangle vertices
    int ax = 40, ay = 70;
    int bx = 50, by = 50;
    int cx = 30, cy = 60;

    // Pivot point
    int px = 30, py = 30;

    // Draw original triangle in YELLOW
    setcolor(YELLOW);
    line(ax, ay, bx, by);
    line(bx, by, cx, cy);
    line(cx, cy, ax, ay);

    // Rotated coordinates
    int axr, ayr, bxr, byr, cxr, cyr;

    rotatePoint(ax, ay, px, py, 45, axr, ayr);
    rotatePoint(bx, by, px, py, 45, bxr, byr);
    rotatePoint(cx, cy, px, py, 45, cxr, cyr);

    // Draw rotated triangle in RED
    setcolor(RED);
    line(axr, ayr, bxr, byr);
    line(bxr, byr, cxr, cyr);
    line(cxr, cyr, axr, ayr);

    getch();
    closegraph();
    return 0;
}

