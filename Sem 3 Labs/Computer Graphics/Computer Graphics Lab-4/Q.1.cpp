
// LiangBarsky.cpp
#include <iostream>
#include <graphics.h>
using namespace std;

void liangBarsky(int x1, int y1, int x2, int y2, int xmin, int ymin, int xmax, int ymax) {
    float t0 = 0.0, t1 = 1.0;
    int dx = x2 - x1, dy = y2 - y1;

    float p[] = {-dx, dx, -dy, dy};
    float q[] = {x1 - xmin, xmax - x1, y1 - ymin, ymax - y1};

    for (int i = 0; i < 4; i++) {
        if (p[i] == 0 && q[i] < 0) return;

        float t = q[i] / p[i];
        if (p[i] < 0) t0 = max(t0, t);
        else t1 = min(t1, t);
    }

    if (t0 > t1) return;

    int newX1 = x1 + t0 * dx;
    int newY1 = y1 + t0 * dy;
    int newX2 = x1 + t1 * dx;
    int newY2 = y1 + t1 * dy;

    line(newX1, newY1, newX2, newY2);
}
/*
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int xmin = 100, ymin = 100, xmax = 400, ymax = 400;
    rectangle(xmin, ymin, xmax, ymax);

    liangBarsky(350, 200, 350, 450, xmin, ymin, xmax, ymax);

    getch();
    closegraph();
    return 0;
} 

*/
