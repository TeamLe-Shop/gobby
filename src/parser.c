#include "parser.h"

#include <stdio.h>

#include "string.h"

void parse(char* line) {
    trimleading(&line);

    char** tokens = NULL;
    size_t token_count = 0;

    split(&tokens, &token_count, line, ' ');

    for (size_t i = 0; i < token_count; i++) {
        printf("Token %zu: %s\n", i, tokens[i]);
    }

    free_tokens(tokens, token_count);
}
