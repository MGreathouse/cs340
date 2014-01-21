#include <stdio.h>

/* print Fahrenheit-Celsius table
    for fahr = 0, 20, ..., 300; floating-point version */

float toCelsius(float fahrenheit);

main() {
    float fahr;
    float lower, upper, step;

    lower = 0;      // lower limit of temperature scale
    upper = 300;    // upper limit
    step = 20;      // step size

    fahr = lower;

    // Title
    printf("Fahrenheit to Celsius\n---------------------\n");

    while (fahr <= upper) {
        printf("%3.0f %6.1f\n", fahr, toCelsius(fahr));
        fahr += step;
    }
}


float toCelsius(float fahrenheit) {
    return ((5.0 / 9.0) * (fahrenheit - 32.0));
}
