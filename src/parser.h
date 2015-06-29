#ifndef PARSER_H
#define PARSER_H

#include <stdbool.h>

enum PrintMode {
    MODE_ASCII, MODE_INTEGER
};

typedef enum PrintMode PrintMode;

struct ParserState {
    bool exec;
    char a;
    char x;
    char y;
    PrintMode printmode;
};

typedef struct ParserState ParserState;

void parse(char* line, ParserState* state);

#endif
