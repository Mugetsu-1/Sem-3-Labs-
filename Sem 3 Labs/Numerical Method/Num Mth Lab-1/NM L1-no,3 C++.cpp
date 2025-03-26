#include <iostream>
#include <cmath>
using namespace std;
double func(double x) {
    return x * x - 4;
}
void secant(double x0, double x1, int max_iterations, double tolerance) {
    double x2;
    for (int i = 0; i < max_iterations; ++i) {
        double f0 = func(x0), f1 = func(x1);
        if (f1 - f0 == 0) {
            cout << "Zero difference in function values, no solution found.\n";
            return;
        }
        x2 = x1 - (f1 * (x1 - x0)) / (f1 - f0);
        if (fabs(x2 - x1) < tolerance) {
            cout << "Converged to the root: " << x2 << "\nFunctional value: " << func(x2) << "\nIterations: " << i + 1 << endl;
            return;
        }
        x0 = x1;
        x1 = x2;
    }
    cout << "Max iterations reached. Approximate root: " << x2 << "\nFunctional value: " << func(x2) << "\nIterations: " << max_iterations << endl;
}

int main() {
    double x0, x1, tolerance;
    int max_iterations;
    cout << "Enter initial guess x0: ";
    cin >> x0;
    cout << "Enter initial guess x1: ";
    cin >> x1;
    cout << "Enter max iterations: ";
    cin >> max_iterations;
    cout << "Enter tolerance: ";
    cin >> tolerance;
    secant(x0, x1, max_iterations, tolerance);
    return 0;
}

