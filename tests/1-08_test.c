/* TEST 1-08 */
#include <stdio.h>
#include <string.h>

#include "../headers/1-08.h"
#include "../headers/test_helpers.h"

struct {
    char *blanks;
    char *tabs;
    char *newlines;
} typedef Expected;

void test(char *file, char *text, Expected total);

int main(void) {
    char *input_file = "input.txt";
    char *text;
    Expected total;

    // Test1
    text = "three blanks\ttwo tabs\tone newline\n";
    total.blanks = "3";
    total.tabs = "2";
    total.newlines = "1";
    test(input_file, text, total);
    printf("\n");

    // Test2
    text = "\tThe sun did not shine.\n"
           "\tIt was too wet to play.\n"
           "\tSo we sat in the house.\n"
           "\tAll that cold, cold, wet day.\n";
    total.blanks = "19";
    total.tabs = "4";
    total.newlines = "4";
    test(input_file, text, total);
    printf("\n");

    // Test3
    text = "";
    total.blanks = "0";
    total.tabs = "0";
    total.newlines = "0";
    test(input_file, text, total);

    return 0;
}

void test(char *file, char *text, Expected total) {
    char *output_file = "output.txt";

    write_to_stdin(file, text);
    run_with_standard_io_redirected(main1, file, output_file);

    FILE *results = fopen("output.txt", "r");
    if (results == NULL) {
        perror("File not found: output.txt\n");
        return;
    }
    const int BUFSIZE = 1024;
    char buf[BUFSIZE];
    int correct = 0;

    while (fgets(buf, BUFSIZE, results)) {
        if (strstr(buf, total.blanks) ||
            strstr(buf, total.tabs) || 
            strstr(buf, total.newlines)) {
            correct++;
        }
    }

    printf("Expected: %s blanks, %s tabs, %s newlines\n", 
            total.blanks, total.tabs, total.newlines);
    printf("got:\n");
    pipe_to_function(file, main1);
    if (correct == 3) {
        printf("SUCCESS!\n");
    } else if (correct > 3) {
        printf("FAILURE: You returned the correct numbers more than three times.\n"
               "I suspect shenanigans.\n");
    } else {
        printf("FAILURE: You got %d/3 correct\n", correct);
        printf("To see the input run: %s | main test-1-08\n", file);
    }
}

