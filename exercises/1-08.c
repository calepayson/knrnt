/* EXERCISE 1-08 */

/* Write a program to count blanks tabs and newlines */

/* When we're writing programs that take input it's useful to be able to test
 * them quickly. It can be a bit tedius to write to stdin each time you're 
 * running the program. I recommend pipping the this file into it's own input 
 * with the following command:
 *
 *      cat exercises/1-08.c | make 1-08
 *
 * 'cat' grabs the contents of a file and prints it to standard out
 * '|' takes whatever is printed to standard out and inputs it to the next program
 * 'make 1-08' our standard make command 
 *
 * Give it a shot! */

#include <stdio.h>

/* NOTE: To pass the tests print each of the counts on a newline. e.g.:
 *     "blanks: 15"
 *     "tabs: 12"
 *     "newlines: 2"
 *
 *  # of blanks must be on line 1, # of tabs must be on line 2, and # of 
 *  newlines must be on line three*/
void main1(void) {
    int c, blanks, tabs, newlines;

    blanks = tabs = newlines = 0;

    while ((c = getchar()) != EOF) {
        switch (c) {
            case ' ':
                blanks++;
                break;
            case '\t':
                tabs++;
                break;
            case '\n':
                newlines++;
                break;
            default:
                break;
        }
    }
    printf("blanks: %d\n"
           "tabs: %d\n"
           "newlines: %d\n", blanks, tabs, newlines);
}

#ifndef TESTING
int main(void) {
    main1();

    return 0;
}
#endif
