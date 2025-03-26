#include <iostream>
#include <cmath>

// Function to be integrated
double f(double x) {
    return x * x;  // Example: x^2
}

// Weights and abscissas for 2-point Gauss quadrature
const double gauss_weights[2] = {1.0, 1.0};
const double gauss_points[2] = {-std::sqrt(1.0 / 3.0), std::sqrt(1.0 / 3.0)};

// Function to calculate Gauss quadrature
double gaussQuadrature(double a, double b, int n) {
    double mid = (a + b) / 2.0;
    double half_length = (b - a) / 2.0;
    double sum = 0.0;

    for (int i = 0; i < n; ++i) {
        double x = mid + half_length * gauss_points[i];
        sum += gauss_weights[i] * f(x);
    }

    return half_length * sum;
}

int main() {
    double a = 0, b = 1; // Limits of integration
    int n = 2; // Number of points (fixed for 2-point Gauss quadrature)

    double result = gaussQuadrature(a, b, n);

    std::cout << "The integral result is: " << result << std::endl;

    return 0;
}

