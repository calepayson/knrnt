# K 'n R 'n T

Kernighan and Ritchie and Tests

## Objective

Workspaces and tests for excercises in The C Programming Language by Kernighan and Ritchie

## Usage

This repo has the follow format:

knrnt
- chapter_1
- chapter_2
- chapter_3
- chapter_4
- chapter_5
- chapter_6
- chapter_7
- chapter_8
- README.md

To start an exercise navigate to the appropriate chapter folder and open the corresponding file

```bash
$ cd chapter_1
$ vim 1-01.c
```

While working on the exercise you can run it by typing 'make <exercise_number>' on the command line like this:

```bash
$ make 1-01
```

When you think you've completed the exercise test it with 'make test-<exercise_number>'. For example

```bash
$ make test-1-01
```

To delete binaries run 'make clean'
