#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void HSLtoRGB(float *hsl, int *rgb);

int main()
{

    int resolution = 4000;
    FILE *output; // A pointer variable of type FILE*
    output = fopen("image.ppm", "w"); // To open the file image.ppm
    fprintf(output, "P3\n%d %d\n255", resolution, resolution);

    long double x1, y1, xtemp;
    int iterations;
    float coloursHSL[3] = {0.0, 1.0, 1.0};
    int coloursRGB[3] = {0};

    int county = 0;
    int countx = 0;
    long double x, y = 1;
    for (int yc = 0; yc < resolution; yc++) {
        x = -2;
        countx = 0;
        for (int xc = 0; xc < resolution; xc++) {
            countx++;
            //TESTING
            x += (float)3/(float)resolution;
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
            coloursHSL[0] = 360 * (iterations/1000);
            HSLtoRGB(coloursHSL, coloursRGB);
            fprintf(output, "\n%d %d %d", coloursRGB[0], coloursRGB[1], coloursRGB[2]);
            //=========
        }
        y -= (float)2/(float)resolution;
        county++;
    }

    int fclose(FILE *output);
    printf("\n%d %d", county, countx);

    return 0;
}

void HSLtoRGB(float *hsl, int *rgb) {
    float C = hsl[1] * hsl[2];
    float X = C * (1 - abs(fmod(hsl[0] / 60.0, 2) - 1));
    float m = hsl[2] - C;
    float rgb1[3] = {0};

    if (hsl[0] == 0) {
        rgb1[0] = 0;
        rgb1[1] = 0;
        rgb1[2] = 0;
    } else if (hsl[0] < 60) {
        rgb1[0] = C;
        rgb1[1] = X;
        rgb1[2] = 0;
    } else if (hsl[0] < 120) {
        rgb1[0] = X;
        rgb1[1] = C;
        rgb1[2] = 0;
    } else if (hsl[0] < 180) {
        rgb1[0] = 0;
        rgb1[1] = C;
        rgb1[2] = X;
    } else if (hsl[0] < 240) {
        rgb1[0] = 0;
        rgb1[1] = X;
        rgb1[2] = C;
    } else if (hsl[0] < 300) {
        rgb1[0] = X;
        rgb1[1] = 0;
        rgb1[2] = C;
    } else {
        rgb1[0] = C;
        rgb1[1] = 0;
        rgb1[2] = X;
    }

    rgb[0] = (rgb1[0] + m)*255;
    rgb[1] = (rgb1[1] + m)*255;
    rgb[2] = (rgb1[2] + m)*255;
}
