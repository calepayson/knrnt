/* TEST 1-07 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../headers/1-07.h"
#include "../headers/test_helpers.h"

#define PASS    1   /* set PASS value */
#define FAIL    0   /* set FAIL VALUE */

int main(void) {
    char *output_file = "output.txt";

    run_with_stdout_redirected(main1, output_file);

    FILE *file = fopen("output.txt", "r");
    if (!file) {
        perror("File not found");
        return 1;
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    char *target = "-1";

    int status = FAIL;
    while ((read = getline(&line, &len, file)) != EOF) {
        if (strstr(line, target) != NULL) {
            status = PASS;
            break;
        }
    }

    if (status) {
        printf("SUCCESS: found -1 in output\n");
    } else {
        printf("FAILURE: did not find EOF value in output\n");
    }

    if (line) {
        free(line);
    }

    fclose(file);
    return 0;
}
