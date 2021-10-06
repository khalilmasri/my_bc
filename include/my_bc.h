#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct tokenizor_struct{
    char **tokens;
    char **token_type;
    int *priority;
    int token_count;
} token;


// ------------------------------------------------------------------------------

#ifndef UTILITY_H
#define UTILITY_H

void print_error(char *error);
int count_open_closed(char *argv);

#endif

// ------------------------------------------------------------------------------

#ifndef STRING_H
#define STRING_H

char *my_itoa(char *dest, unsigned int number, int size, int base);
long my_atoi(char *number_string, int size);
int my_strcmp(char *ptr1, char *ptr2);
int my_is_digit(char c);

#endif

// -------------------------------------------------------------------------------

#ifndef LEXER_H
#define LEXER_H

token *get_lexer(char *argv);

#endif