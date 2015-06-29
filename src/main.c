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
        printf("Reading input files not implemented!");
    }
    return 0;
}

void welcome() {
    printf("Gobby Interpreter v0.1\n");
}

void read_stdin() {
    char* line = NULL;
    size_t linecap;
    ssize_t length;
    welcome();
    printf(">>> ");
    while ((length = getline(&line, &linecap, stdin))) {
        parse(line);
        printf(">>> ");
    }
    free(line);
}
