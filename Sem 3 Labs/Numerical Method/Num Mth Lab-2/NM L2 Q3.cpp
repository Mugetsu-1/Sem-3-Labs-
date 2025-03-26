#include <iostream>
using namespace std;

int fact(int n) { return (n <= 1) ? 1 : n * fact(n - 1); }

void backwardDiffTable(double table[][10], double* x, double* y, int n) {
    for (int i = 0; i < n; i++) table[i][0] = y[i];
    for (int j = 1; j < n; j++)
        for (int i = n - 1; i >= j; i--)
            table[i][j] = table[i][j - 1] - table[i - 1][j - 1];
}

double interpolate(double* x, double table[][10], int n, double xp) {
    double result = table[n - 1][0], h = x[1] - x[0], s = (xp - x[n - 1]) / h;
    for (int i = 1; i < n; i++) {
        double term = table[n - 1][i];
        for (int j = 0; j < i; j++) term *= (s + j);
        result += term / fact(i);
    }
    return result;
}

int main() {
    int n;
    cout << "Enter number of data points: ";
    cin >> n;
    double x[n], y[n], table[n][10] = {0};
    cout << "Enter data points (x and y): ";
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
    backwardDiffTable(table, x, y, n);
    double xp;
    cout << "Enter interpolation point: ";
    cin >> xp;
    cout << "Interpolated value at x = " << xp << " is " << interpolate(x, table, n, xp) << endl;
    return 0;
}

