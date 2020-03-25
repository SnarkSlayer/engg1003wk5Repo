#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float f(float x);

int main()
{
    int N = 500;
    float x1 = 0, x2 = 2;
    float dx = (x2 - x1) / N;
    float result;
    float sum = 0;

    for (int k = 1; k < N; k++) {
        float x;
        x = x1 + k*dx;
        sum += f(x);
    }

    result = dx * (0.5*f(x1) + sum + 0.5*f(x2));
    printf("The value is: %f\n", result);

    return 0;
}

float f(float x) {
    float result = expf(x*x);
    return result;
}
