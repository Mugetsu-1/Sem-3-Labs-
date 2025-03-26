#include <iostream>
#include <cmath>
using namespace std;

void cubicSplineInterpolation(double x[], double y[], int n, double xp, double& yp) {
    double h[n-1], a[n], b[n-1], c[n] = {0}, d[n-1], alpha[n-1], l[n] = {1}, mu[n] = {0}, z[n] = {0};

    for (int i = 1; i < n - 1; i++) {
        h[i] = x[i+1] - x[i];
        alpha[i] = (3/h[i]) * (y[i+1] - y[i]) - (3/h[i-1]) * (y[i] - y[i-1]);
    }
    for (int i = 1; i < n - 1; i++) {
        l[i] = 2 * (x[i+1] - x[i-1]) - h[i-1] * mu[i-1];
        mu[i] = h[i] / l[i];
        z[i] = (alpha[i] - h[i-1] * z[i-1]) / l[i];
    }
    for (int j = n - 2; j >= 0; j--) {
        c[j] = z[j] - mu[j] * c[j+1];
        b[j] = (y[j+1] - y[j]) / h[j] - h[j] * (c[j+1] + 2 * c[j]) / 3;
        d[j] = (c[j+1] - c[j]) / (3 * h[j]);
    }

    int i = 0;
    while (xp > x[i + 1]) i++;
    yp = y[i] + b[i] * (xp - x[i]) + c[i] * pow((xp - x[i]), 2) + d[i] * pow((xp - x[i]), 3);
}

int main() {
    int n;
    cout << "Enter the number of data points: ";
    cin >> n;
    double x[n], y[n];
    cout << "Enter the data points (x and y): ";
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];

    double xp, yp;
    cout << "Enter the interpolation point: ";
    cin >> xp;
    cubicSplineInterpolation(x, y, n, xp, yp);
    cout << "The interpolated value at x = " << xp << " is " << yp << endl;
    return 0;
}

