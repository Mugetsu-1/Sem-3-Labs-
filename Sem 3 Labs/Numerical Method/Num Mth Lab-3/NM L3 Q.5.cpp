#include <iostream>
#include <cmath>

// Function to be integrated
double f(double x) {
    return x * x;  // Example: x^2
}

// Function to calculate Simpson's 3/8 rule
double simpsons38(double a, double b, int n) {
    if (n % 3 != 0) {
        std::cout << "n must be a multiple of 3.\n";
        return -1;
    }

    double h = (b - a) / n;
    double sum = f(a) + f(b);

    for (int i = 1; i < n; ++i) {
        if (i % 3 == 0) {
            sum += 2 * f(a + i * h);
        } else {
            sum += 3 * f(a + i * h);
        }
    }

    return (3 * h / 8) * sum;
}

int main() {
    double a = 0, b = 1; // Limits of integration
    int n = 6; // Number of intervals (must be multiple of 3)

    double result = simpsons38(a, b, n);

    if (result != -1) {
        std::cout << "The integral result is: " << result << std::endl;
    }

    return 0;
}

