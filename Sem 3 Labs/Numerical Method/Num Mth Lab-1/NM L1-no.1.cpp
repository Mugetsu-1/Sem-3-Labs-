#include <iostream>
#include <cmath>
using namespace std;

double func(double x) {
    return exp(-x) - x;
}

void bisection(double initial_guess, int max_iterations) {
    double a = initial_guess - 1, b = initial_guess + 1, c;
    if (func(a) * func(b) >= 0) {
        cout << "Invalid interval.\n";
        return;
    }

    for (int i = 0; i < max_iterations && (b - a) / 2.0 > 1e-6; i++) {
        c = (a + b) / 2.0;
        if (func(c) == 0.0) break;
        (func(c) * func(a) < 0) ? b = c : a = c;
    }

    cout << "Estimated root: " << c << "\nFunctional value: " << func(c) << endl;
}

int main() {
    double initial_guess;
    int max_iterations;
    cout << "Enter initial guess: ";
    cin >> initial_guess;
    cout << "Enter max iterations: ";
    cin >> max_iterations;
    bisection(initial_guess, max_iterations);
    return 0;
}

