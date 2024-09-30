#include <stdio.h>

int fact(int n) {
    if (n == 0)
        return 1;
    else
        return n * fact(n - 1);
}

int main() {
    int n, i, j;
    float x[100], y[100][100], X, h, p, result, term;

    printf("Enter the number of data points: ");
    scanf("%d", &n);

    printf("Enter the data points (x, y):\n");
    for (i = 0; i < n; i++) {
        printf("x[%d]: ", i);
        scanf("%f", &x[i]);
        printf("y[%d]: ", i);
        scanf("%f", &y[i][0]);
    }

    // Forward difference table
    for (j = 1; j < n; j++) {
        for (i = 0; i < n - j; i++) {
            y[i][j] = y[i + 1][j - 1] - y[i][j - 1];
        }
    }

    printf("Enter the interpolation point X: ");
    scanf("%f", &X);

    h = x[1] - x[0]; // Assuming equal spacing
    p = (X - x[0]) / h;

    // Applying Newton's forward interpolation formula
    result = y[0][0];
    for (i = 1; i < n; i++) {
        term = y[0][i];
        for (j = 1; j <= i; j++) {
            term *= (p - j + 1) / j;
        }
        result += term;
    }

    printf("Interpolated value using Newton Forward Difference at X = %.3f is %.3f\n", X, result);

    return 0;
}
