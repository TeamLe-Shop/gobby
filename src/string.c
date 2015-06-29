#include "string.h"

#include <string.h>
#include <ctype.h>
#include <stddef.h>
#include <stdio.h>

void trim(char** str) {
    char* new_end;
    while (isspace(**str)) {
        (*str)++;
    }
    new_end = *str + strlen(*str);
    while (isspace(*(new_end - 1))) {
        new_end--;
    }
    *new_end = '\0';
}

bool starts(char* str, char* str2) {
    return memcmp(str, str2, strlen(str2));
}

void split(TokenList* list, char* str, char delimiter) {
    if (*str == '\0') { // String is empty.
        return;
    }
    char* temp = str;
    char* start = str;
    while (true) {
        temp++;
        ptrdiff_t diff = temp - start;
        if (*temp == delimiter) {
            char* t = strndup(start, diff);
            TokenList_Add(list, t);
            free(t);
            start = temp + 1;
        } else if (*temp == '\0') {
            char* t = strndup(start, diff);
            TokenList_Add(list, t);
            free(t);
            return;
        }
    }
}
