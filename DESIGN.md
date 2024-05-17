# KnRnT Design Doc

## Context and Scope

The C Programming Language by Brian Kernighan and Dennis Ritchie is "The Book"
for learning C. Despite being published in the 80's it has remained relevant
as many college courses still use The Book as their textbook. Within and outside
of these courses many students use the exercises as practice. Despite this,
there are no tests for the exercises in The Book (at least, I couldn't find 
any).

## Goals and Non-Goals

This project aims to provide tests for the exercises in the book in a format
that is approachable by learners with no programming experience.

### Goals

- Provide tests for each exercise in The Book.
- Provide a workspace for each exercise in The Book.
- Provide a basic command line interface usable by begginners.

### Non-Goals

- Write perfect tests.
- Model proper structuring of a C project.

## Design

### Overview

knrnt
├── DESIGN.md
├── exercises
│   └── example.c
├── headers
│   └── example.h
├── helpers
│   └── example_helpers.c
├── Makefile
├── README.md
└── tests
    └── example_test.c

### DESIGN.md

An collection of all design decisions in this project and their rationale.

### exercises

This folder contains all the exercise workspaces. Each file contains the 
instructions for an exercise and a workspace to complete the exercise. Some
code will already be present to reduce the boilerplate that needs to be written
by the user and to allow for easy testing of the user's code.

### headers

This folder contains all the header files used by files in this project.

### helpers

This folder contains C libraries for the project. To make compilation easier
there will only be two files: book_helpers and test_helpers. Book helpers will
contain functions used in the book so that the user doesn't have to rewrite 
them or learn how to make librariesto do the exercises. Test helper will 
contain functions to help with the testing of user programs.

### Makefile

The Makefile contains the compilation rules. It will take two types of 
commands, an exercise number and an instruction. The instruction could be 
'test' or 'clean'. Test will test an exercise based on the number supplied and
clean will remove any binaries.

The makefile will only compile the needed files for any given exercise and
test. If one of the required files is already compiled the makefile will use 
that compilation instead of recompiling it.

### README.md

This file contains a brief overview of the goals of the project and
instructions for using it.

### tests

This folder contains the test files for each exercise. They will be linked to
the exercise with a header file. 
