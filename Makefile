# This is a Makefile. Makefiles are used to help streamline compilation.
#
# This one is a little complex so don't feel like you have to understand 
# everything that is going on it.
#
# The main flow is: 
# 	if "make" is called with a filename:
# 		compile and run that file
# 	if "make test-" is called with a filename:
# 		compile and run that file and its tests.
#
# If you're interested in learning more about Makefiles this is an amazing
# resource:
#
# https://makefiletutorial.com/


# Set compiler
CC = clang

# Set default compiler flags
CFLAGS = -Wall -Wpedantic -Werror -Wextra

# Set default compiler flags while testing
TFLAGS = $(CFLAGS) -DTESTING

vpath %.c exercises
vpath %.h headers
vpath %_test.c tests

# Default target: show usage
all:
	@echo "Usage: make <exercise_number> or make test-<exercise_number>"
	@echo "Example: make 1-01 or make test-1-01"
	@echo "Delete binary files with 'make clean'"

# Pattern rule for compiling and running exercises
%: %.c
	@$(CC) $(CFLAGS) $< -o $@.out
	@./$@.out

# Pattern rule for compiling and running tests
test-%: %.o %_test.o test_helpers.o
	@$(CC) $*_test.o $*.o test_helpers.o -o $*_test.out
	@./$*_test.out
	@rm $*.o $*_test.o test_helpers.o >/dev/null

# Pattern rule for compiling exercise with header
%.o: %.c %.h
	@$(CC) $(TFLAGS) -c exercises/$*.c

# Pattern rule for compiling test with exercise header
%_test.o: %_test.c %.h test_helpers.h
	@$(CC) $(TFLAGS) -c tests/$*_test.c

test_helpers.o: helpers/test_helpers.c test_helpers.h
	@$(CC) $(CFLAGS) -c helpers/test_helpers.c

# Clean up compiled files
clean:
	@echo "Cleaning ..."
	@find . -type f \( -name "*.o" -o -name "*.out" -o -name "*.exe" -o -name "*.txt" \) ! -name "Makefile" -exec rm {} \;	
	@echo "Done"
