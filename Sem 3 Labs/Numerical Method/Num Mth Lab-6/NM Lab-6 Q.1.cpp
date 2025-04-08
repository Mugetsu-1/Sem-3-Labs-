//Laplace Equation
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

void gaussElimination(double A[4][4], double B[4]) {
    // Forward elimination
    for (int i = 0; i < 4; i++) {
        // Make the diagonal element of A[i][i] as 1
        for (int k = i + 1; k < 4; k++) {
            double factor = A[k][i] / A[i][i];
            for (int j = 0; j < 4; j++) {
                A[k][j] -= factor * A[i][j];
            }
            B[k] -= factor * B[i];
        }
    }

    // Back-substitution
    double X[4];
    for (int i = 3; i >= 0; i--) {  // Start from the last row
        X[i] = B[i];
        for (int j = i + 1; j < 4; j++) {
            X[i] -= A[i][j] * X[j];  // Subtract terms already computed
        }
        X[i] /= A[i][i];  // Divide by the diagonal element
    }

    // Display solution
    cout << "\nSolution:\n";
    for (int i = 0; i < 4; i++) {
        cout << "x" << i + 1 << " = " << fixed << setprecision(6) << X[i] << endl;
    }
}

int main() {
    double B[4], l, r, b, t;

    double A[4][4] = {
        {-4, 1, 1, 0},
        {1, -4, 0, 1},
        {1, 0, -4, 1},
        {0, 1, 1, -4}
    };

    // Input boundary values (LRBT format)
    cout << "Enter the boundary value (form LRBT):";
    cin >> l >> r >> b >> t;

    // Calculate the B values based on the boundary conditions
    B[0] = -(t + l);
    B[1] = -(t + r);
    B[2] = -(b + l);
    B[3] = -(r + b);

    // Call Gauss Elimination to solve the system
    gaussElimination(A, B);

    return 0;
}

