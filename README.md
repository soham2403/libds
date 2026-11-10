# libds

A collection of generic data structures implemented in C.

## Data Structures

- Dynamic Array
- Doubly Linked List

## Requirements

- GCC
- GNU Make
- Bear (optional, for clangd)

## Build

Build the static library:

    make

Build example:

    make example

Run tests:

    make test

Clean build:

    make clean

## Usage

Include the required header:

    #include <libds/DArray.h>

Link against the static library:

    gcc -Iinclude main.c build/libds.a -o main

## License

See LICENSE.
