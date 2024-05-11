/* EXCERCISE 1-03 */

/* Modify the temperature conversion program to print a heading above the 
 * table */

#include <stdio.h>

/* Here we define main as main1 to facilitate testing. Use your imagination and
 * pretend it just says main. */

void main1(void) {
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;      /* lower limit of temperature table */
    upper = 300;    /* upper limit */
    step = 20;      /* step size */

    fahr = lower;
    while (fahr <= upper) {
        celsius = 5 * (fahr-32) /9;
        printf("%3.0f\t%6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}

/* Here's the real main function with a conditional compilation macro. When we
 * compile and run the file it runs main1. But if we compile and test the file
 * it's hidden by the macro and the compiler only sees main in 1-03_test.c */

#ifndef TESTING
int main(void) {
    main1();

    return 0;
}
#endif
