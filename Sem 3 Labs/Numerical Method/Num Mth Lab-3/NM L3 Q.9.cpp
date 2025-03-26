#include <iostream>
#include <cmath>

// Function to be integrated
double f(double x, double y) {
    return x * y;  // Example: x * y
}

// Function to calculate double integration using Trapezoidal rule
double trapezoidalDoubleIntegral(double a, double b, double c, double d, int nx, int ny) {
    double hx = (b - a) / nx;
    double hy = (d - c) / ny;

    double sum = 0.0;
    for (int i = 0; i <= nx; ++i) {
        for (int j = 0; j <= ny; ++j) {
            double x = a + i * hx;
            double y = c + j * hy;
            double weight = 1.0;

            if (i == 0 || i == nx) weight *= 0.5;
            if (j == 0 || j == ny) weight *= 0.5;

            sum += weight * f(x, y);
        }
    }

    return hx * hy * sum;
}

int main() {
    double a = 0, b = 1; // Limits of integration for x
    double c = 0, d = 1; // Limits of integration for y
    int nx = 10; // Number of intervals for x
    int ny = 10; // Number of intervals for y

    double result = trapezoidalDoubleIntegral(a, b, c, d, nx, ny);

    std::cout << "The integral result is: " << result << std::endl;

    return 0;
}

