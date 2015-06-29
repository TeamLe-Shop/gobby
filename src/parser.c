#include "parser.h"

#include <stdio.h>
#include <string.h>

#include "string.h"

void parse(char* line, ParserState* state) {
    trim(&line);
    TokenList* list = TokenList_New();
    split(list, line, ' ');

    if (list->size > 0) {
        if (strcmp(list->tokens[0], "printv") == 0) {
            if (list->size < 2) {
                printf("WARNING: `printv` requires at least 1 parameter!\n");
                return;
            }
            char* variable = list->tokens[1];
            if (strcmp(variable, "a") == 0) {
                if (state->printmode == MODE_INTEGER) {
                    printf("%d", state->a);
                } else if (state->printmode == MODE_ASCII) {
                    printf("%c", state->a);
                }
            } else {
                printf("WARNING: '%s' is not a variable!\n", variable);
            }
        } else if (strcmp(list->tokens[0], "setv") == 0) {
            if (list->size < 3) {
                printf("WARNING: `setv` requires at least 2 parameters!\n");
                return;
            }
            char* variable = list->tokens[1];
            char* value = list->tokens[2];

            if (strcmp(variable, "a") == 0) {
                state->a = 0xFF & atoi(value);
            } else {
                printf("WARNING: '%s' is not a variable!\n", variable);
            }
        } else if (strcmp(list->tokens[0], "mode") == 0) {
            if (list->size < 2) {
                printf("WARNING: `mode` requires at least 1 parameter!\n");
                return;
            }

            char* value = list->tokens[1];

            if (strcmp(value, "ascii") == 0) {
                state->printmode = MODE_ASCII;
            } else if (strcmp(value, "int") == 0) {
                state->printmode = MODE_INTEGER;
            } else {
                printf("WARNING: `%s` is not a valid print mode!\n", value);
            }
        }
    }

    TokenList_Destroy(list);
}
