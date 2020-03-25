#include <stdio.h>
#include <stdlib.h>

int main()
{
    float x[9] = {1,2,3,4,5,6,7,8,9};
    float variance, mean;
    float sum1 = 0, sum2 = 0;
    int n;

    for (n = 0; n < 9; n++) {
        sum1 += x[n];
    }

    mean = sum1 / n;

    for (n = 0; n < 9; n++) {
        sum2 = sum2 + (x[n] - mean)*(x[n] - mean);
    }

    variance = sum2 / (n - 1);

    printf("Mean: %f\nVariance: %f\n", mean, variance);

    return 0;
}
