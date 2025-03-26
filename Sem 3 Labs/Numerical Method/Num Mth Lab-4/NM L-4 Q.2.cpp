#include <stdio.h>
#define SIZE 10

void gaussJordan(float a[SIZE][SIZE], int n) {
    // Applying Gauss-Jordan elimination
    for (int i = 0; i < n; i++) {
        // Check if the pivot is zero and avoid division by zero
        if (a[i][i] == 0.0) {
            printf("Mathematical Error: Singular matrix detected.\n");
            return;
        }

        // Normalize the pivot row (make the pivot element 1)
        float pivot = a[i][i];
        for (int j = 0; j <= n; j++) {
            a[i][j] /= pivot;
        }

        // Make all other elements in the current column zero
        for (int k = 0; k < n; k++) {
            if (k != i) {
                float factor = a[k][i];
                for (int j = 0; j <= n; j++) {
                    a[k][j] -= factor * a[i][j];
                }
            }
        }
    }

    // Display the solution
    printf("Solution:\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d] = %.2f\n", i + 1, a[i][n]);
    }
}

int main() {
    int n;
    float a[SIZE][SIZE];

    printf("Enter the number of equations: ");
    scanf("%d", &n);

    printf("Enter the augmented matrix (coefficients and constants):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            scanf("%f", &a[i][j]);
        }
    }

    gaussJordan(a, n);
    return 0;
}

