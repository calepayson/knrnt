/* TEST 1-05 */

/* This file is almost the same as 1-04_test.c If you're curious about what 
 * different parts of this program do, go check out that file. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../headers/1-05.h"
#include "../headers/test_helpers.h"

#define BUFF_SIZE   10      /* set maximum buffer size */
#define PASS        1       /* Test succeeded */
#define FAIL        0       /* Test has not succeeded */

float fahr_to_cels(float f);

int main(void) {
    char *output_file = "output.txt";

    // print the result to output.txt
    run_with_stdout_redirected(main1, output_file);

    FILE *file = fopen(output_file, "r");
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    int lower = 0;
    int upper = 300;
    int step = 20;

    int status = FAIL;

    char target_c[BUFF_SIZE];
    char target_f[BUFF_SIZE];

    float celsius;
    float fahr = (float)upper;
    while ((read = getline(&line, &len, file)) != -1) {
        celsius = fahr_to_cels(fahr);

        snprintf(target_c, sizeof(target_c), "%.1f", celsius);
        snprintf(target_f, sizeof(target_f), "%.0f", fahr);

        if (strstr(line, target_c) != NULL && strstr(line, target_f) != NULL) {
            if (fahr > lower) {
                fahr -= (float)step;
            } else {
                status = PASS;
            }
        }
    }
    
    if (status) {
        printf("SUCCESS: correctly printed celsius to fahrenheit\n");
    } else {
        printf("FAILURE: celsius to fahrenheit printed incorrectly\n"
               "Check that the printf statement follows the formatting "
               "guidelines at the top of 1-05.c\n");
    }

    fclose(file);
    return 0;
}

float fahr_to_cels(float f) {
    return (5.0 / 9.0) * (f - 32);
}


