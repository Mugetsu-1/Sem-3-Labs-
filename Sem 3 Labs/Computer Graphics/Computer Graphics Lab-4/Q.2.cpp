// SutherlandHodgeman.cpp
#include <iostream>
#include <graphics.h>
using namespace std;

void clip(int poly[][2], int &n, int edge, bool isXmin, bool isYmin) {
    int out[20][2], outCount = 0;

    for (int i = 0; i < n; i++) {
        int x1 = poly[i][0], y1 = poly[i][1];
        int x2 = poly[(i + 1) % n][0], y2 = poly[(i + 1) % n][1];

        bool inside1 = isXmin ? x1 >= edge : isYmin ? y1 >= edge : x1 <= edge;
        bool inside2 = isXmin ? x2 >= edge : isYmin ? y2 >= edge : x2 <= edge;

        if (inside1 != inside2) {
            float t = isXmin || !isYmin ? (float)(edge - x1) / (x2 - x1) : (float)(edge - y1) / (y2 - y1);
            out[outCount][0] = isXmin || !isYmin ? edge : x1 + t * (x2 - x1);
            out[outCount][1] = isXmin || !isYmin ? y1 + t * (y2 - y1) : edge;
            outCount++;
        }

        if (inside2) {
            out[outCount][0] = x2;
            out[outCount][1] = y2;
            outCount++;
        }
    }

    n = outCount;
    for (int i = 0; i < n; i++) {
        poly[i][0] = out[i][0];
        poly[i][1] = out[i][1];
    }
}

void sutherlandHodgeman(int poly[][2], int n, int xmin, int ymin, int xmax, int ymax) {
    clip(poly, n, xmin, true, false);
    clip(poly, n, xmax, false, false);
    clip(poly, n, ymin, false, true);
    clip(poly, n, ymax, false, false);

    for (int i = 0; i < n; i++) {
        line(poly[i][0], poly[i][1], poly[(i + 1) % n][0], poly[(i + 1) % n][1]);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int xmin = 100, ymin = 100, xmax = 400, ymax = 400;
    rectangle(xmin, ymin, xmax, ymax);

    int poly[][2] = {{200, 280}, {250, 360}, {220, 290}, {350, 200}};
    int n = 4;
    sutherlandHodgeman(poly, n, xmin, ymin, xmax, ymax);

    getch();
    closegraph();
    return 0;
}

