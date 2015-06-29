#ifndef STRING_H
#define STRING_H

#include <stdlib.h>
#include <stdbool.h>

#include "token.h"

/* Trim leading and trailing whitespace of a string. */
void trim(char** string);

/* Return if `str` starts with `str2`. */
bool starts(char* str, char* str2);

/* Splits `str` into tokens stored in `result`, using specified delimiter.
 *
 * Immediately returns with `token_count` if `str` is empty.
 */
void split(TokenList* list, char* str, char delimiter);

#endif
