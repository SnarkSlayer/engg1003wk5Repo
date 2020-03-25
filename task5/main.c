#include <stdio.h>
#include <stdlib.h>

int main()
{
    const int N = 100;
    char nums[N + 1];

    for (int i = 0; i <= N; i++) {
        nums[i] = 1;
    }

    for (int i = 2; i <= N; i++) {
        if (nums[i] == 1) {
            for (int j = 2; j * i <= N; j++) {
                nums[j * i] = 0;
            }
        }
    }

    printf("The following numbers are prime:\n");
    for (int i = 2; i <= N; i++) {
        if (nums[i] == 1) {
            printf("%d\n", i);
        }
    }

    return 0;
}
