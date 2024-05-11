/* TEST 1-04 */

/* This is a slightly more involved test file */

/* import the necessary libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* import the header file of the exercise */
#include "../headers/1-04.h"
#include "../headers/test_helpers.h"

/* define magic numbers (This way if we need to change them we only have to 
 * change them once */
#define BUFF_SIZE   10      /* set maximum buffer size */
#define PASS        1       /* Test succeeded */
#define FAIL        0       /* Test has not succeeded */

/* declare functions (the compiler reads files top-to-bottom so we need to let
 * it know there's a function used in main that won't be defined until later */
float cels_to_fahr(float c);

int main(void) {
    // print the result of 1-04.c to output.txt
    char *output_file = "output.txt";
    run_with_stdout_redirected(celsius_to_fahrenheit, output_file);

    /* define some variables to help us read the results */
    FILE *file = fopen(output_file, "r");
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    /* define constants to define the temps we'll check for */
    int lower = 0;
    int upper = 300;
    int step = 20;

    /* assume program fails tests until proven otherwise */
    int status = FAIL;

    /* variables to store string representations of the floats we calculate */
    char target_c[BUFF_SIZE];
    char target_f[BUFF_SIZE];

    /* initialize the temperature variables */
    float fahr;
    float celsius = (float)lower;

    /* read through every output line
     *      if a line contains the first value of celsius and farenheit
     *          calculate the next value for each
     *      if all values have been found and calculated
     *          signal that the program passed the test */
    while ((read = getline(&line, &len, file)) != -1) {
        fahr = cels_to_fahr(celsius);

        snprintf(target_c, sizeof(target_c), "%.0f", celsius);
        snprintf(target_f, sizeof(target_f), "%.1f", fahr);

        if (strstr(line, target_c) != NULL && strstr(line, target_f) != NULL) {
            if (celsius < upper) {
                celsius += (float)step;
            } else {
                status = PASS;
            }
        }
    }
    
    /* print the result of the test */
    if (status) {
        printf("SUCCESS: correctly printed celsius to fahrenheit\n");
    } else {
        printf("FAILURE: celsius to fahrenheit printed incorrectly\n"
               "Check that the printf statement follows the formatting "
               "guidelines at the top of 1-04.c\n");
    }

    /* close the file and signal that main ran successfully */
    fclose(file);
    return 0;
}

/* function to calculate fahrenheit from celsius */
float cels_to_fahr(float c) {
    return (9.0 / 5.0) * c + 32.0;
}


