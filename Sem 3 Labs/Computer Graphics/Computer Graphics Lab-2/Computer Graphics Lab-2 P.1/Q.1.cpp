#include <graphics.h>
#include<iostream>
using namespace std;
// Function to plot points in all 8 octants of the circle
void plotCircle(int xc, int yc, int x, int y) {
    putpixel(xc + x, yc + y, WHITE); // Octant 1
    putpixel(xc - x, yc + y, WHITE); // Octant 4
    putpixel(xc + x, yc - y, WHITE); // Octant 8
    putpixel(xc - x, yc - y, WHITE); // Octant 5
    putpixel(xc + y, yc + x, WHITE); // Octant 2
    putpixel(xc - y, yc + x, WHITE); // Octant 3
    putpixel(xc + y, yc - x, WHITE); // Octant 7
    putpixel(xc - y, yc - x, WHITE); // Octant 6
}

// Function to draw a circle using the midpoint circle algorithm
void drawCircle(int xc, int yc, int r) {
    int x = r, y = 0; // Initial point on the circle radius
    int p = 1 - r;    // Decision parameter
    
    // Plot the initial point and its reflections
    plotCircle(xc, yc, x, y);
    
    while (x > y) {
        y++;
        
        // Update the decision parameter based on the midpoint algorithm
        if (p <= 0) {
            p = p + 2*y + 1; // Mid point is inside the circle
        } else {
            x--;
            p = p + 2*y - 2*x + 1; // Mid point is outside or on the circle
        }
        
        // Plot the new points in all octants
        plotCircle(xc, yc, x, y);
    }
}

int main() {
    int gd = DETECT, gm; 
    initgraph(&gd, &gm, (char*)"C:\\TDM-GCC-64\\lib");

    int xc , yc, r ; // Center and radius of the circle
    cout<<"Enter the Co-ordinate and radius\n";
    cin>>xc>>yc>>r;
    drawCircle(xc, yc, r); // Call the function to draw the circle
    
    getch(); 
    closegraph(); 
    return 0;
}

