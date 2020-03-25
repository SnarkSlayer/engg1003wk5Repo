#include <stdio.h>
#include <stdlib.h>

float arithmetic(float x, float y);

int main()
{
    float x = 1, y = 5;
    float result;

    result = arithmetic(x, y);
    printf("%f plus %f is %f\n", x, y, result);

    return 0;
}

float arithmetic(float x, float y) {
    return x + y;
}
