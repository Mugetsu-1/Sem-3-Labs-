#include <iostream>
#include <iomanip>
using namespace std;

int factorial(int n) {
    int fact = 1;
    for (int i = 2; i <= n; i++)
        fact *= i;
    return fact;
}

// Function to compute central divided difference table
void centralDifferenceTable(double table[][10], double x[], double y[], int n) {
    for (int i = 0; i < n; i++)
        table[i][0] = y[i];
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            table[i][j] = (table[i + 1][j - 1] - table[i][j - 1]) / (x[i + j] - x[i]);
        }
    }
}

// Function to interpolate using Newton's central divided difference formula
double interpolate(double x[], double table[][10], int n, double xp) {
    double result = table[0][0];
    double h = x[1] - x[0];
    double u = (xp - x[0]) / h;
    for (int i = 1; i < n; i++) {
        double term = table[0][i];
        for (int j = 0; j < i; j++) {
            term *= (u - j);
        }
        term /= factorial(i);
        result += term;
    }
    return result;
}

int main() {
    int n;
    cout << "Enter the number of data points: ";
    cin >> n;
    double x[n], y[n];
    cout << "Enter the data points (x and y):" << endl;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    double table[n][10] = {0};
    centralDifferenceTable(table, x, y, n);
    double xp;
    cout << "Enter the interpolation point: ";
    cin >> xp;
    cout << fixed << setprecision(6);
    cout << "The interpolated value at x = " << xp << " is " << interpolate(x, table, n, xp) << endl;
    return 0;
}

