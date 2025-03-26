//Write a program to calculate integration using composite Simpson’s 1/3 rule.
#include <iostream>
#include <cmath>
using namespace std;

double function(double x) {
    // Define the function to integrate here
    return pow(x, 5); // Example function: f(x) = x^5
}

double composite_simpsons_rule(double a, double b, int n) {
    if (n % 2 != 0) {
        cout << "Number of subintervals must be even." << endl;
        return -1;
    }

    double h = (b - a) / n;
    double sum = function(a) + function(b);

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        if (i % 2 == 0) {
            sum += 2 * function(x);
        } else {
            sum += 4 * function(x);
        }
    }

    return (h / 3) * sum;
}

int main() {
    double a, b;
    int n;

    // Input the limits of integration and number of subintervals
    cout << "Enter the limits of integration (a and b): ";
    cin >> a >> b;
    cout << "Enter the number of subintervals (n): ";
    cin >> n;

    double result = composite_simpsons_rule(a, b, n);
    if (result != -1) {
        cout << "The integral value is: " << result << endl;
    }

    return 0;
}

