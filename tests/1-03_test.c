/* TEST 1-03 */

/* Welcome to our first real test program! I've added some comments to help
 * explain what's going on */

/* Import all the necessary libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* You'll see this later. For now know that these lines are used to aid 
 * readability later in the program */
#define BETWEEN 1   /* program is between the start and end lines */
#define OUTSIDE 0   /* program is outside of the start and end lines */

/* The conditional compilation macro in the exercise file means this is the 
 * only main function the compiler sees when this file is run */
int main(void) {
    /* Here we declare a pointer (more on this later) to the exercise file */
    FILE *file;
    char *file_name = "exercises/1-03.c";

    /* Define some constants to help our search */

    const char *start_line =   "void main1(void) {";        /* starting at this line */
    const char *end_line =     "while (fahr <= upper) {";   /* and ending at this line */
    const char *target_line =  "printf(";                   /* look for this line */

    char *line = NULL;  /* declare a "string" (really a pointer to a string */
    size_t len = 0;     /* declare a variable for the length of that string */
    ssize_t read;       /* declare a var for status of a getline function */

    file = fopen(file_name, "r");   /* open the exercise file in read mode */

    /* if there is no file return an error */
    if (file == NULL) {
        perror("Failed to open file");
        return 1;
    }

    int state = OUTSIDE;    /* We start outside of the main1 function */

    /* read each line one by one. For each line:
     *      if we haven't found main1
     *          look for it and let us know when we've hit it
     *      if we are in main1
     *          look for the start of the while loop
     *              and fail the test if we find it
     *          look for our target line
     *              and pass the test if we find it */
    while ((read = getline(&line, &len, file)) != EOF) {
        if (state == OUTSIDE) {
            if (strstr(line, start_line) != NULL) {
                state = BETWEEN;
            }
        } else if (state == BETWEEN) {
            if (strstr(line, end_line) != NULL) {
                printf("FAILURE: no printf statement found between the start "
                       "the start of main and the start of the while loop\n");
                break;
            } else if (strstr(line, target_line) != NULL) {
                printf("SUCCESS: header line declard with printf\n");
                break;
            }
        }
    }          

    /* signal that the main function ran successfully */
    return 0;
}


