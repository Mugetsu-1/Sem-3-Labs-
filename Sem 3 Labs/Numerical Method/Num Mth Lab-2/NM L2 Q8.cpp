#include <iostream>
#include <cmath>
using namespace std;

void leastSquaresQuadratic(double x[], double y[], int n, double& a, double& b, double& c) {
    double sX = 0, sY = 0, sX2 = 0, sX3 = 0, sX4 = 0, sXY = 0, sX2Y = 0;

    for (int i = 0; i < n; i++) {
        sX += x[i];
        sY += y[i];
        sX2 += x[i] * x[i];
        sX3 += x[i] * x[i] * x[i];
        sX4 += x[i] * x[i] * x[i] * x[i];
        sXY += x[i] * y[i];
        sX2Y += x[i] * x[i] * y[i];
    }

    double den = n * (sX2 * sX4 - sX3 * sX3) - sX * (sX * sX4 - sX2 * sX3) + sX2 * (sX * sX3 - sX2 * sX2);
    a = (sY * (sX2 * sX4 - sX3 * sX3) - sX * (sXY * sX4 - sX3 * sX2Y) + sX2 * (sXY * sX3 - sX2Y * sX2)) / den;
    b = (n * (sXY * sX4 - sX3 * sX2Y) - sY * (sX * sX4 - sX2 * sX3) + sX2 * (sX * sX2Y - sXY * sX2)) / den;
    c = (n * (sX2 * sX2Y - sXY * sX3) - sX * (sX * sX2Y - sY * sX3) + sY * (sX * sX2 - sX2 * sX)) / den;
}

int main() {
    int n;
    cout << "Enter number of data points: ";
    cin >> n;
    double x[n], y[n];
    cout << "Enter data points (x and y): ";
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];

    double a, b, c;
    leastSquaresQuadratic(x, y, n, a, b, c);
    cout << "Quadratic curve: y = " << a << " + " << b << "x + " << c << "x^2" << endl;
    return 0;
}

