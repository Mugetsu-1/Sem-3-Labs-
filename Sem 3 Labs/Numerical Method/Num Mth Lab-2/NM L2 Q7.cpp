#include <iostream>
using namespace std;

// Function to calculate the least squares approximation for linear data
void leastSquaresApproximation(double x[], double y[], int n, double& a, double& b) {
    double sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;

    for (int i = 0; i < n; i++) {
        sumX += x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
        sumX2 += x[i] * x[i];
    }

    // Calculating the coefficients a and b for the line y = a + bx
    b = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    a = (sumY - b * sumX) / n;
}

int main() {
    int n;
    cout << "Enter the number of data points: ";
    cin >> n;

    double x[n], y[n];
    cout << "Enter the data points (x and y):" << endl;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    double a, b;
    leastSquaresApproximation(x, y, n, a, b);

    cout << "The least squares approximation line is y = " << a << " + " << b << "x" << endl;
    return 0;
}

