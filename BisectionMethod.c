#include <stdio.h>
#include <math.h>

#define EPSILON 0.00001
#define f(x) (pow(x, 2) - 4 * x - 10)

int main() {
    double a, b, c;
    printf("Enter the values of a and b: ");
    scanf("%lf %lf", &a, &b);

    if (f(a) * f(b) >= 0) {
        printf("Invalid interval.\n");
        return 1;
    }

    while ((b - a) >= EPSILON) {
        c = (a + b) / 2;
        if (fabs(f(c)) < EPSILON) break;
        if (f(c) * f(a) < 0) b = c; else a = c;
    }

    printf("Root of equation from Bisection method is : %.5lf\n", c);
    return 0;
}
