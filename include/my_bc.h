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

typedef struct order_list{
    char *method;
    int priority;
    struct order_list *next;
}order;

#define MAX_STR_LEN 10
#define MAX_TYPE_LEN 10

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
char* my_strcpy(char *dest, char *src);

#endif

// -------------------------------------------------------------------------------

#ifndef LEXER_H
#define LEXER_H


#define ADD "ADD"
#define SUB "SUB"
#define MULT "MULT"
#define DIV "DIV"
#define MOD "MOD"
#define VAL "VAL"
#define SPACE "SPACE"
#define OPEN_PAR "OPEN_PAR"
#define CLOSE_PAR "CLOSE_PAR"
#define UNKNOWN "UNKNOWN"

#define PRIORITY_ONE 1
#define PRIORITY_TWO 2
#define PRIORITY_THREE 3
#define PRIORITY_FOUR 4
#define PRIORITY_FIVE 5

token *get_lexer(char *argv);
int solving_tree(token *token);

#endif
