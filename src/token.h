#ifndef TOKEN_H
#define TOKEN_H

#include <stddef.h>

struct TokenList {
    char** tokens;
    size_t size;
};

typedef struct TokenList TokenList;

/* Allocate memory for a new TokenList and return the pointer. */
TokenList* TokenList_New();

/* Free all memory used by a TokenList. */
void TokenList_Destroy(TokenList* list);

/* Add a token to the TokenList. */
void TokenList_Add(TokenList* list, char* token);

#endif /* TOKEN_H */
