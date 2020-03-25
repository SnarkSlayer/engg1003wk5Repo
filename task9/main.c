#include <stdio.h>
#include <stdlib.h>

unsigned int fib(void);

int main()
{
    for (int i = 1; i < 10; i++) {
        printf("%d %u\n", i, fib());
    }

    return 0;
}

unsigned int fib() {
    static int x0 = 0, x1 = 1;
    int temp = x1;

    x1 += x0;
    x0 = temp;

    return x0;
}
