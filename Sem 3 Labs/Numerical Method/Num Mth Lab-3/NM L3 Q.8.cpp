#include <iostream>
#include <cmath>

// Function to be integrated
double f(double x) {
    return x * x;  // Example: x^2
}

// Function to calculate Romberg integration
double rombergIntegration(double a, double b, int n) {
    double h = b - a;
    double* R1 = new double[n];
    double* R2 = new double[n];

    R1[0] = (f(a) + f(b)) * h / 2.0;
    for (int j = 1; j < n; ++j) {
        h /= 2.0;
        double sum = 0.0;

        for (int i = 1; i <= (1 << (j - 1)); ++i) {
            sum += f(a + (2 * i - 1) * h);
        }

        R2[0] = 0.5 * R1[0] + sum * h;
        for (int k = 1; k <= j; ++k) {
            R2[k] = R2[k - 1] + (R2[k - 1] - R1[k - 1]) / (std::pow(4.0, k) - 1.0);
        }

        std::swap(R1, R2);
    }

    double result = R1[n - 1];
    delete[] R1;
    delete[] R2;

    return result;
}

int main() {
    double a = 0, b = 1; // Limits of integration
    int n = 4; // Number of iterations

    double result = rombergIntegration(a, b, n);

    std::cout << "The integral result is: " << result << std::endl;

    return 0;
}

