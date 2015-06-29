#ifndef PARSER_H
#define PARSER_H

#include <stdbool.h>

struct ParserState {
    bool exec;
};

void parse(char* line);

#endif
