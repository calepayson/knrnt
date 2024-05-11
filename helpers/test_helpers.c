#include <stdio.h>
#include <stdlib.h>

void write_to_stdin(char *file_name, char *text) {
    FILE *input = fopen(file_name, "w");
    if (input == NULL) {
        perror("Failed to open input.txt\n");
    }
    fprintf(input, "%s", text);
    fclose(input);
}

void run_with_standard_io_redirected(void (func)(void), char *input_file, char *output_file) {
    freopen(input_file, "r", stdin);
    freopen(output_file, "w", stdout);
    func();
    fclose(stdout);
    fclose(stdin);
}

void run_with_stdout_redirected(void (func)(void), char *output_file) {
    freopen(output_file, "w", stdout);
    func();
    freopen("/dev/tty", "w", stdout);
}
