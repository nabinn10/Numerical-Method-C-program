#include <stdio.h>
#include <math.h>

#define EPSILON 0.00001
#define g(x) (sqrt(4 * x + 10))  // Example: g(x) is derived from the equation x^2 - 4x - 10 = 0

int main() {
    double x0, x1;

    // Take input from the user for the initial guess
    printf("Enter the initial guess x0: ");
    scanf("%lf", &x0);

    // Fixed Point Iteration
    do {
        x1 = g(x0);
        if (fabs(x1 - x0) < EPSILON) break;
        x0 = x1;
    } while (1);

    // Print the result
    printf("Root: %.5lf\n", x1);

    return 0;
}
