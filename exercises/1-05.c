/* EXERCISE 1-05 */

/* Modify the temperature conversion program to print the table in reverse 
 * order, that is, from 300 degrees to 0. */

/* To pass the tests please use the following format for the print statement:
 *     printf("%3d %6.1f\n", variable_1, variable_2); */

#include <stdio.h>

/* I've included the program from the book so that you don't have to write 
 * a bunch of boilerplate code. Please keep the function name as main1 */

void main1(void)
{
    int fahr;

    for (fahr = 0; fahr <= 300; fahr = fahr + 20) {
        printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
    }
}

#ifndef TESTING
int main(void) {
    main1();

    return 0;
}
#endif
