//Write a program to calculate integration using Trapezoidal rule. 

#include <iostream>
#include <cmath>
using namespace std;

double function(double x) {
    // Define the function to integrate here
    return pow(x, 2); // Example function: f(x) = x^2
}

double trapezoidal_rule(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = function(a) + function(b);

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        sum += 2 * function(x);
    }

    return (h / 2) * sum;
}

int main() {
    double a, b;
    int n;

    // Input the limits of integration and number of subintervals
    cout << "Enter the limits of integration (a and b): ";
    cin >> a >> b;
    cout << "Enter the number of subintervals (n): ";
    cin >> n;

    double result = trapezoidal_rule(a, b, n);
    cout << "The integral value is: " << result << endl;

    return 0;
}

