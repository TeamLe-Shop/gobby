#ifndef STRING_H
#define STRING_H

#include <stdlib.h>
#include <stdbool.h>

/* Trim leading and trailing whitespace of a string. */
void trim(char** string);

/* Return if `str` starts with `str2`. */
bool starts(char* str, char* str2);

/* Splits `str` into tokens stored in `result`, using specified delimiter.
 *
 * Immediately returns with `token_count` if `str` is empty.
 */
void split(char*** result, size_t* token_count, char* str, char delimiter);

/* Frees `tokens` and all of its tokens assuming it was created by
 * split() or other 'token-list' producing functions.
 */
void free_tokens(char** tokens, size_t token_count);

#endif
