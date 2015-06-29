#include <stdio.h>

#include <stdlib.h>

#include "parser.h"

void read_stdin();

void welcome();

int main(int argc, char* argv[])
{
    if (argc < 2) {
        // The user has not specified the input file, so we will read from
        // stdin.
        read_stdin();
    } else {
        // TODO: Implement reading from files.
        printf("Reading input files not implemented!\n");
    }
    return 0;
}

void welcome() {
    printf("Gobby Interpreter v0.1\n");
}

void read_stdin() {
    char line[128];
    welcome();
    printf(">>> ");
    while (fgets(line, 128, stdin)) {
        parse(line);
        printf(">>> ");
    }
}
