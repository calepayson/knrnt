/* EXCERCISE 1-01 */

/* Run the "hello, world" program on your system. Experiment with leaving out
 * parts of the program, to see what error messages you get. */

/* NOTE: you'll quickly notice some differences between the following code and
 * the code in the textbook.
 *
 *  - #ifndef TESTING: This is a macro that tells the compiler "if the program
 *                     is compiled with the TESTING flag, don't compile this 
 *                     function. If you comment it out and then run:
 *                     "make test-1-01" compilation will fail because there's
 *                     also a function called main in the test file.
 *
 *  - int main(void): Here we're declaring the variable types that main takes 
 *                    as input and returns as output. Main takes no input 
 *                    (void) and returns and integer (int)
 *
 *  - return 0;: Returning an integer from main is used for error handling and
 *               is considered best practice. Returning a 0 signifies there
 *               was no error while running main. Any other number represents
 *               an error code. You've likely seen this when navigating to a
 *               non-existent page on a website: "Error 404"
 *
 *  - #endif: This ends the macro for conditional compilation. */

#include <stdio.h>

#ifndef TESTING     /* Start of conditional compilation */
int main(void) {
    printf("hello, world\n");

    return 0;
}
#endif              /* End of conditional compilation */
