#include <iostream>
#include <cmath> // For abs()
using namespace std;

void gaussElimination(float a[][10], float b[], int n) {
    // Forward elimination
    for (int i = 0; i < n; i++) {
        // Partial pivoting (improves numerical stability)
        int maxRow = i;
        for (int k = i + 1; k < n; k++) {
            if (abs(a[k][i]) > abs(a[maxRow][i])) {
                maxRow = k;
            }
        }

        // Swap rows if needed
        if (maxRow != i) {
            for (int j = 0; j < n; j++)
                swap(a[i][j], a[maxRow][j]);
            swap(b[i], b[maxRow]);
        }

        // Check for singular matrix
        if (a[i][i] == 0.0) {
            cout << "Mathematical Error: Singular matrix detected.\n";
            return;
        }

        // Eliminate column below pivot
        for (int k = i + 1; k < n; k++) {
            float factor = a[k][i] / a[i][i];
            for (int j = i; j < n; j++)
                a[k][j] -= factor * a[i][j];
            b[k] -= factor * b[i];
        }
    }

    // Back substitution
    float x[10];
    for (int i = n - 1; i >= 0; i--) {
        x[i] = b[i];
        for (int j = i + 1; j < n; j++)
            x[i] -= a[i][j] * x[j];
        x[i] /= a[i][i];
    }

    // Display solution
    cout << "Solution:\n";
    for (int i = 0; i < n; i++)
        cout << "x[" << i + 1 << "] = " << x[i] << endl;
}

int main() {
    int n;
    float a[10][10], b[10];

    cout << "Enter the number of equations: ";
    cin >> n;

    cout << "Enter the coefficients of the equations followed by the constant terms:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
        cin >> b[i]; // Constant term for equation i
    }

    gaussElimination(a, b, n);
    return 0;
}

