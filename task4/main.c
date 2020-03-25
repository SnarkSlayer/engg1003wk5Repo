#include <stdio.h>
#include <stdlib.h>

int isPrime(int x);

int main()
{
    for (int testNum = 0; testNum < 20; testNum++) {
        if (isPrime(testNum)) {
            printf("%d is prime\n", testNum);
        }
    }

    return 0;
}

int isPrime(int x) {
    for (int i = 2; i <= (float)x/2.0; i++) {
        if (x % i == 0) {
            return 0;
        }
    }
    if (x > 1) {
        return 1;
    } else {
        return 0;
    }
}
