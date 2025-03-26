#include <iostream>
#include <iomanip>
using namespace std;

// Function dy/dx = x + y
double dydx(double x, double y) {
    return x + y;
}

// Euler's method
double euler(double x0, double y0, double h, double x) {
    double y = y0;
    while (x0 < x) {
        y = y + h * dydx(x0, y);
        x0 += h;
    }
    return y;
}

// Heun's method
double heun(double x0, double y0, double h, double x) {
    double y = y0;
    while (x0 < x) {
        double k1 = dydx(x0, y);
        double k2 = dydx(x0 + h, y + h * k1);
        y = y + (h / 2) * (k1 + k2);
        x0 += h;
    }
    return y;
}

// Runge-Kutta 4th order method
double rk4(double x0, double y0, double h, double x) {
    double y = y0;
    while (x0 < x) {
        double k1 = h * dydx(x0, y);
        double k2 = h * dydx(x0 + h / 2, y + k1 / 2);
        double k3 = h * dydx(x0 + h / 2, y + k2 / 2);
        double k4 = h * dydx(x0 + h, y + k3);
        y = y + (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        x0 += h;
    }
    return y;
}

int main() {
    double x0 = 0, y0 = 1, x = 0.4;

    cout << fixed << setprecision(4);

    cout << "For step size h = 0.1:\n";
    cout << "Using Euler's method: " << euler(x0, y0, 0.1, x) << endl;
    cout << "Using Heun's method: " << heun(x0, y0, 0.1, x) << endl;
    cout << "Using RK4 method: " << rk4(x0, y0, 0.1, x) << endl;

    cout << "\nFor step size h = 0.2:\n";
    cout << "Using Euler's method: " << euler(x0, y0, 0.2, x) << endl;
    cout << "Using Heun's method: " << heun(x0, y0, 0.2, x) << endl;
    cout << "Using RK4 method: " << rk4(x0, y0, 0.2, x) << endl;

    return 0;
}

