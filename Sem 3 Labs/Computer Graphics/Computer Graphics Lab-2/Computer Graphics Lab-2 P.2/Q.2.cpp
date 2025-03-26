#include <graphics.h>

// Function to plot points in all 4 quadrants of the ellipse
void plotEllipse(int xc, int yc, int x, int y) {
    putpixel(xc + x, yc + y, WHITE); // Quadrant 1
    putpixel(xc - x, yc + y, WHITE); // Quadrant 2
    putpixel(xc + x, yc - y, WHITE); // Quadrant 4
    putpixel(xc - x, yc - y, WHITE); // Quadrant 3
}

// Function to draw an ellipse using the midpoint ellipse algorithm
void drawEllipse(int xc, int yc, int rx, int ry) {
    int x = 0, y = ry; // Initial point on the ellipse
    // Initial decision parameters
    int rx2 = rx * rx;
    int ry2 = ry * ry;
    int p1 = ry2 - (rx2 * ry) + (0.25 * rx2);
    int dx = 2 * ry2 * x;
    int dy = 2 * rx2 * y;

    // Region 1
    while (dx < dy) {
        // Plot the points in the four quadrants
        plotEllipse(xc, yc, x, y);

        // Check the decision parameter
        if (p1 < 0) {
            x++;
            dx = dx + 2 * ry2;
            p1 = p1 + dx + ry2;
        } else {
            x++;
            y--;
            dx = dx + 2 * ry2;
            dy = dy - 2 * rx2;
            p1 = p1 + dx - dy + ry2;
        }
    }

    // Region 2
    int p2 = (ry2) * ((x + 0.5) * (x + 0.5)) + (rx2) * ((y - 1) * (y - 1)) - (rx2 * ry2);
    while (y > 0) {
        // Plot the points in the four quadrants
        plotEllipse(xc, yc, x, y);

        // Check the decision parameter
        if (p2 > 0) {
            y--;
            dy = dy - 2 * rx2;
            p2 = p2 + rx2 - dy;
        } else {
            y--;
            x++;
            dx = dx + 2 * ry2;
            dy = dy - 2 * rx2;
            p2 = p2 + dx - dy + rx2;
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TDM-GCC-64\\lib");

    int xc = 200, yc = 200; // Center of the ellipse
    int rx = 100, ry = 50; // Radii of the ellipse
    drawEllipse(xc, yc, rx, ry); // Call the function to draw the ellipse

    getch();
    closegraph();
    return 0;
}

