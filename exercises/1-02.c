/* EXERCISE 1-02 */

/* Experiment to find out what happens when printf's argument string contains 
 * \c, where c is some character not listed above */

#include <stdio.h>

#ifndef TESTING
int main(void) {
    printf("hello, world\n");

    return 0;
}
#endif
