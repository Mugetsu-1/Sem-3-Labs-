#include <stdio.h>
#include <math.h>

void Matrix(float matrix[3][3], float vec[3], float result[3])   //multiplyMatrixWithVector
{  
    for (int i = 0; i < 3; i++) {
        result[i] = 0;
        for (int j = 0; j < 3; j++) {
            result[i] += matrix[i][j] * vec[j];
        }
    }
}

float computeNorm(float vec[3]) {
    float sum = 0;
    for (int i = 0; i < 3; i++) {
        sum += vec[i] * vec[i];
    }
    return sqrt(sum);
}

float powerMethod(float matrix[3][3], float vec[3], int maxIterations, float tolerance) {
    float eigenvalue = 0;
    float newVec[3];

    for (int iter = 0; iter < maxIterations; iter++) {
        Matrix(matrix, vec, newVec);
        
        float norm = computeNorm(newVec);
        for (int i = 0; i < 3; i++) {
            vec[i] = newVec[i] / norm;
        }

        eigenvalue = norm;

        // Check for convergence
        if (fabs(norm - eigenvalue) < tolerance) {
            break;
        }
    }
    return eigenvalue;
}

int main() {
    float matrix[3][3] = {{4, -1, 0},
                          {-1, 4, -1},
                          {0, -1, 3}};
    float vec[3] = {1, 1, 1};  // Initial guess vector
    float eigenvalue = powerMethod(matrix, vec, 1000, 1e-6);

    printf("The eigenvalue is: %.6f\n", eigenvalue);
    
    return 0;
}

