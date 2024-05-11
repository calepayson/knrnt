#pragma once

void write_to_stdin(char *file_name, char *text);
void run_with_standard_io_redirected(void (func)(void), char *input_file, char *output_file);
void run_with_stdout_redirected(void (func)(void), char *output_file);
