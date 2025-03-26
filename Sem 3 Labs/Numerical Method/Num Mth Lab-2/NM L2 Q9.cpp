#include <iostream>
#include <cmath>
using namespace std;

void leastSquaresPolynomial(double* x, double* y, int n, int m, double* coeff) {
    double X[2 * m + 1] = {0}, B[m + 1][m + 2] = {0};

    for (int i = 0; i <= 2 * m; i++)
        for (int j = 0; j < n; j++)
            X[i] += pow(x[j], i);

    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= m; j++)
            B[i][j] = X[i + j];

    for (int i = 0; i <= m; i++)
        for (int j = 0; j < n; j++)
            B[i][m + 1] += pow(x[j], i) * y[j];

    for (int i = 0; i <= m; i++) {
        for (int k = i + 1; k <= m; k++) {
            if (B[k][i] > B[i][i]) {
                for (int j = 0; j <= m + 1; j++) {
                    double temp = B[i][j];
                    B[i][j] = B[k][j];
                    B[k][j] = temp;
                }
            }
        }
    }

    for (int i = 0; i <= m; i++) {
        for (int k = i + 1; k <= m; k++) {
            double t = B[k][i] / B[i][i];
            for (int j = 0; j <= m + 1; j++)
                B[k][j] -= t * B[i][j];
        }
    }

    for (int i = m; i >= 0; i--) {
        coeff[i] = B[i][m + 1];
        for (int j = 0; j <= m; j++)
            if (j != i)
                coeff[i] -= B[i][j] * coeff[j];
        coeff[i] /= B[i][i];
    }
}

int main() {
    int n, m;
    cout << "Enter the number of data points: ";
    cin >> n;

    double x[n], y[n];
    cout << "Enter the data points (x and y):" << endl;
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];

    cout << "Enter the degree of the polynomial: ";
    cin >> m;

    double coeff[m + 1];
    leastSquaresPolynomial(x, y, n, m, coeff);

    cout << "The least squares approximation polynomial is: y = ";
    for (int i = 0; i <= m; i++) {
        cout << coeff[i] << "x^" << i;
        if (i != m) cout << " + ";
    }
    cout << endl;

    return 0;
}

