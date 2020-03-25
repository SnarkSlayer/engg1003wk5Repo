#include <stdio.h>
#include <stdlib.h>

int main()
{
    const int N = 5;
    float data[5] = {1.2, 8.4, 10.8, -8.234, 3.1};
    float maxValue = data[0];

    for (int i = 0; i < N; i++) {
        if (maxValue < data[i]) {
            maxValue = data[i];
        }
    }

    printf("Highest number is: %f\n", maxValue);

    return 0;
}
