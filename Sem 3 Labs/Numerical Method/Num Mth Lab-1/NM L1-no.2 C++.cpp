#include <iostream>
#include <cmath>
using namespace std;

double func(double x) {
    return exp(-x) - x;
}

double derivative(double x) {
    return -exp(-x) - 1;
}

void newton(double initial_guess, int max_iterations, double tolerance) {
    double x = initial_guess;
    for (int i = 0; i < max_iterations; ++i) {
        double fx = func(x), fx_prime = derivative(x);
        if (fx_prime == 0) {
            cout << "Derivative is zero, no solution found.\n";
            return;
        }
        double new_x = x - fx / fx_prime;
        if (fabs(new_x - x) < tolerance) {
            cout << "Converged to the root: " << new_x << "\nFunctional value: " << func(new_x) << "\nIterations: " << i + 1 << endl;
            return;
        }
        x = new_x;
    }
    cout << "Max iterations reached. Approximate root: " << x << "\nFunctional value: " << func(x) << "\nIterations: " << max_iterations << endl;
}

int main() {
    double initial_guess, tolerance;
    int max_iterations;
    cout << "Enter initial guess: ";
    cin >> initial_guess;
    cout << "Enter max iterations: ";
    cin >> max_iterations;
    cout << "Enter tolerance: ";
    cin >> tolerance;
    newton(initial_guess, max_iterations, tolerance);
    return 0;
}

