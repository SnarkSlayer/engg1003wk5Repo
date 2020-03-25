#include <stdio.h>
#include <stdlib.h>

int arithmetic(float x, float y, int operation);

int main()
{
    float x = 1, y = 5;
    char result;
    int operation;
    printf("0: Addition\n1: Subtraction\n2: Multiplication\n3: Division\n");
    scanf("%d", &operation);

    arithmetic(x, y, operation);

    return 0;
}

int arithmetic(float x, float y, int operation) {
    switch (operation) {
    case 0:
        printf("%f plus %f is %f\n", x, y, x + y);
        break;
    case 1:
        printf("%f minus %f is %f\n", x, y, x - y);
        break;
    case 2:
        printf("%f times %f is %f\n", x, y, x * y);
        break;
    case 3:
        if (y == 0) {
            printf("Division by zero error");
            break;
        }
        printf("%f divided by %f is %f\n", x, y, x / y);
        break;
    default:
        printf(("Illegal operation %d", operation));
    }
    return 0;
}
