#include <stdio.h>

int main() {
    int n, i, j;
    float x[100], y[100][100], X, result, term;

    printf("Enter the number of data points: ");
    scanf("%d", &n);

    printf("Enter the data points (x, y):\n");
    for (i = 0; i < n; i++) {
        printf("x[%d]: ", i);
        scanf("%f", &x[i]);
        printf("y[%d]: ", i);
        scanf("%f", &y[i][0]);
    }

    // Divided difference table
    for (j = 1; j < n; j++) {
        for (i = 0; i < n - j; i++) {
            y[i][j] = (y[i + 1][j - 1] - y[i][j - 1]) / (x[i + j] - x[i]);
        }
    }

    printf("Enter the interpolation point X: ");
    scanf("%f", &X);

    // Applying Newton's divided difference formula
    result = y[0][0];
    for (i = 1; i < n; i++) {
        term = y[0][i];
        for (j = 0; j < i; j++) {
            term *= (X - x[j]);
        }
        result += term;
    }

    printf("Interpolated value using Newton divided Difference at X = %.3f is %.3f\n", X, result);

    return 0;
}
