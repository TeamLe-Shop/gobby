#include "parser.h"

#include <stdio.h>

#include "string.h"

void parse(char* line) {
    trim(&line);

    TokenList* list = TokenList_New();

    split(list, line, ' ');

    for (size_t i = 0; i < list->size; i++) {
        printf("Token %zu: %s\n", i, list->tokens[i]);
    }

    TokenList_Destroy(list);
}
