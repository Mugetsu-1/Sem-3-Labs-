#include <iostream>
using namespace std;

double interpolate(double* x, double* y, int n, double xp) {
    double result = 0.0;
    for (int i = 0; i < n; i++) {
        double term = y[i];
        for (int j = 0; j < n; j++) {
            if (j != i) term *= (xp - x[j]) / (x[i] - x[j]);
        }
        result += term;
    }
    return result;
}

int main() {
    int n;
    cout << "Enter the number of data points: ";
    cin >> n;

    double x[n], y[n];
    cout << "Enter the data points (x and y): ";
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];

    double xp;
    cout << "Enter the interpolation point: ";
    cin >> xp;

    cout << "The interpolated value at x = " << xp << " is " << interpolate(x, y, n, xp) << endl;
    return 0;
}

