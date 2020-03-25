#include <stdio.h>
#include <stdlib.h>


int main()
{
    int resolution = 40000;
    FILE *output; // A pointer variable of type FILE*
    output = fopen("image.ppm", "w"); // To open the file image.ppm
    fprintf(output, "P3\n%d %d\n255", resolution, resolution);

    long double x1, y1, xtemp;
    int iterations;
    int p;
    int R, G, B;
    for (long double y = 1; y >= -1; y -= 0.00005) {
        for (long double x = -2; x <= 1; x += 0.000075) {
            //TESTING
            x1 = 0; y1 = 0; xtemp = 0;
            iterations = 0;
            while((x1*x1 + y1*y1 < 4) && iterations < 1000) {
                xtemp = x1*x1 - y1*y1 + x;
                y1 = 2*x1*y1 + y;
                x1 = xtemp;
                iterations++;
            }
            //=======
            //Printing
            p = 255 * (iterations/1000);
            R = p, G = p, B = p;
            fprintf(output, "\n%d %d %d", R, G, B);
            //=========
        }
    }
    int fclose(FILE *output);
    return 0;
}

