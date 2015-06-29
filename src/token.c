#include "token.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

TokenList* TokenList_New()
{
    TokenList* new = malloc(sizeof(TokenList));
    new->tokens = NULL;
    new->size = 0;

    return new;
}

void TokenList_Destroy(TokenList* list)
{
    for (size_t i = 0; i < list->size; i++) {
        free(list->tokens[i]);
    }
    free(list->tokens);
    free(list);
}

void TokenList_Add(TokenList* list, char* token)
{
    list->tokens = realloc(list->tokens, sizeof(char*) * (list->size + 1));
    list->tokens[list->size] = strdup(token);
    list->size++;
}
