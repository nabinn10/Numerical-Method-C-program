#include <stdio.h>
#include <math.h>

#define EPSILON 0.00001
#define f(x) (pow(x, 3) - 5 * x - 10)

int main() {
    double x0, x1, x2;

    printf("Enter the values of x0 and x1: ");
    scanf("%lf %lf", &x0, &x1);

    do {
        x2 = x1 - (f(x1) * (x1 - x0)) / (f(x1) - f(x0));
        x0 = x1;
        x1 = x2;
    } while (fabs(f(x2)) >= EPSILON);

    printf("Root of equation using Secant Method method is  %.5lf\n", x2);
    return 0;
}
