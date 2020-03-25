#include <stdio.h>
#include <stdlib.h>

float f(float x);
float diff(float x, float h);

int main()
{
    float h = 0.0001;
    printf("%f\n", diff(0, h));
    printf("%f\n", diff(1, h));
    printf("%f\n", diff(-1, h));

    return 0;
}

float f(float x) {
    return x*x + 2*x - 1;
}

float diff(float x, float h) {
    return ((f(x + h) - f(x)) / h);
}
