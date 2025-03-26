#include <iostream>
#include <cmath>
using namespace std;

double g(double x) {
    return exp(-x);
}

void fixedPointIteration(double x0, int max_iterations, double tolerance) {
    double x1;
    for (int i = 0; i < max_iterations; ++i) {
        x1 = g(x0);
        if (fabs(x1 - x0) < tolerance) {
            cout << "Converged to the root: " << x1 << "\nFunctional value: " << exp(-x1) - x1 << "\nIterations: " << i + 1 << endl;
            return;
        }
        x0 = x1;
    }
    cout << "Max iterations reached. Approximate root: " << x1 << "\nFunctional value: " << exp(-x1) - x1 << "\nIterations: " << max_iterations << endl;
}

int main() {
    double x0, tolerance;
    int max_iterations;
    cout << "Enter initial guess x0: ";
    cin >> x0;
    cout << "Enter max iterations: ";
    cin >> max_iterations;
    cout << "Enter tolerance: ";
    cin >> tolerance;
    fixedPointIteration(x0, max_iterations, tolerance);
    return 0;
}

