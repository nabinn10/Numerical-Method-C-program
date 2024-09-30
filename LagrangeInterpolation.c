#include <stdio.h>

int main() {
    int n, i, j;
    float x[100], y[100], X, result = 0.0, term;

    printf("Enter the number of data points: ");
    scanf("%d", &n);

    printf("Enter the data points (x, y):\n");
    for (i = 0; i < n; i++) {
        printf("x[%d]: ", i);
        scanf("%f", &x[i]);
        printf("y[%d]: ", i);
        scanf("%f", &y[i]);
    }

    printf("Enter the interpolation point X: ");
    scanf("%f", &X);

    // Lagrange interpolation formula
    for (i = 0; i < n; i++) {
        term = y[i];
        for (j = 0; j < n; j++) {
            if (i != j)
                term = term * (X - x[j]) / (x[i] - x[j]);
        }
        result += term;
    }

    printf("Interpolated value using lagrange interpolation at X = %.3f is %.3f\n", X, result);

    return 0;
}
