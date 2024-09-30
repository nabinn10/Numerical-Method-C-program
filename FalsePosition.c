#include <stdio.h>
#include <math.h>

#define EPSILON 0.00001
#define f(x) (pow(x, 3) - 4 * x - 10)

int main() {
    double a, b, c;

    printf("Enter the values of a and b: ");
    scanf("%lf %lf", &a, &b);

    if (f(a) * f(b) >= 0) {
        printf("Invalid interval.\n");
        return 1;
    }

    while (fabs(b - a) >= EPSILON) {
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));
        if (fabs(f(c)) < EPSILON) break;
        if (f(c) * f(a) < 0) b = c;
        else a = c;
    }

    printf("Root of equation from False position method is : %.5lf\n", c);
    return 0;
}
