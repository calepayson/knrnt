/* TEST 1-10 */

#include <stdio.h>
#include <string.h>

#include "../headers/1-10.h"
#include "../headers/test_helpers.h"

void test(char *input, char *expected);

int main(void) {
    char *input;    
    char *expected;

    // Test 1
    input =     "tab: \t, backspace: \b, backslash \\";
    expected =  "tab: \\t, backspace: \\b, backslash \\\\";
    printf("TEST 1\n");
    test(input, expected);
    printf("\n");

    // Test 2
    input =     "Hello world";
    expected =  "Hello world";
    printf("TEST 2\n");
    test(input, expected);
    printf("\n");

    // Test 3
    input =     "\t \\ \b \t \\ \b";
    expected =  "\\t \\\\ \\b \\t \\\\ \\b";
    printf("TEST 3\n");
    test(input, expected);
    printf("\n");

    return 0;
}

void test(char *input, char *expected) {
    char *input_file = "input.txt";
    char *output_file = "output.txt";
    write_to_stdin(input_file, input);
    run_with_standard_io_redirected(main1, input_file, output_file);

    FILE *output = fopen(output_file, "r");
    if (output == NULL) {
        perror("File not found: output.txt\n");
        return;
    }

    const int BUFSIZE = 1024;
    char buf[BUFSIZE];

    if (fgets(buf, BUFSIZE, output)) {
        printf("Expected: %s\n", expected);
        printf("Got:      %s\n", buf);
        if (strcmp(expected, buf) == 0) {
            printf("SUCCESS!\n");
        } else {
            printf("FAILURE!\n");
        }
    } else {
        printf("FAILURE: you need to output the result\n");
    }
}
