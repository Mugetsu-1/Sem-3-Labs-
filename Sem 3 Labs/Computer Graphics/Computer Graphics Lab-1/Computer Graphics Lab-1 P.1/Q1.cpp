#include <graphics.h>
#include <iostream>
#include <conio.h>
using namespace std;

void DDA(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = max(abs(dx), abs(dy));
    
    float Xinc = dx / (float) steps;
    float Yinc = dy / (float) steps;
    
    float x = x1;
    float y = y1;
    
    for (int i = 0; i <= steps; i++) {
        putpixel(x, y, WHITE);
        x += Xinc;
        y += Yinc;
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"C:\\TDM-GCC-64\\lib");

    int x1, y1, x2, y2;
    cout << "Enter the coordinates of the first point (x1, y1): ";
    cin >> x1 >> y1;
    cout << "Enter the coordinates of the second point (x2, y2): ";
    cin >> x2 >> y2;

    DDA(x1, y1, x2, y2);
    
    getch();
    closegraph();
    return 0;
}

