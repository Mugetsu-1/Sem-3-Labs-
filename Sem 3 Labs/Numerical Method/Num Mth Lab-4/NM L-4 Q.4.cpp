#include <stdio.h>
#include <math.h>

#define SIZE 10
#define EPSILON 0.001 // Convergence tolerance
#define MAX_ITERATIONS 100 // To avoid infinite loops

void gaussSeidel(float a[SIZE][SIZE], float b[SIZE], int n) {
    float x[SIZE] = {0}; // Initial guess (all zeros)
    int iterations = 0;
    float error;

    do {
        error = 0;

        // Iterate through each equation
        for (int i = 0; i < n; i++) {
            float old_xi = x[i]; // Store the old value of x[i]
            float sum = b[i];

            // Calculate the sum of known values
            for (int j = 0; j < n; j++) {
                if (j != i) {
                    sum -= a[i][j] * x[j];
                }
            }

            // Update x[i] using the new values directly
            x[i] = sum / a[i][i];

            // Calculate the maximum error (difference between old and new value)
            if (fabs(x[i] - old_xi) > error) {
                error = fabs(x[i] - old_xi);
            }
        }

        iterations++;

        if (iterations > MAX_ITERATIONS) {
            printf("Solution did not converge.\n");
            return;
        }
    } while (error > EPSILON);

    // Display the solution
    printf("Solution after %d iterations:\n", iterations);
    for (int i = 0; i < n; i++) {
        printf("x[%d] = %.4f\n", i + 1, x[i]);
    }
}

int main() {
    int n;
    float a[SIZE][SIZE], b[SIZE];

    printf("Enter the number of equations: ");
    scanf("%d", &n);

    printf("Enter the coefficients of the equations followed by the constant terms:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%f", &a[i][j]);
        }
        scanf("%f", &b[i]); // Constant term
    }

    gaussSeidel(a, b, n);
    return 0;
}

