#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct tokenizor_struct
{
    char **tokens;
    char **token_type;
    int *priority;
    int token_count;
} token;

typedef struct rpn
{
    char *token;
    struct rpn *next;
} rpn;

typedef struct operators
{
    char *token;
    int priority;
    struct operators *next;
} operators;

//struct AST
typedef struct tree_struct
{
    char *type;
    char *value; //guess numbers can be converted to int when needed later?
    struct tree_struct *left;
    struct tree_struct *right;
} tree;

#define MAX_STR_LEN 100
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

char *my_itoa(int);
long my_atoi(char *number_string, int size);
int my_strcmp(char *ptr1, char *ptr2);
int is_digit(char c);
int is_par(char c);
int is_op(char c);
char *my_strcpy(char *dest, char *src);
char *add_whitespace(char *);

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
int solving_tree(rpn *, token *);

#endif

// -------------------------------------------------------------------------------

#ifndef POSTFIX_H
#define POSTFIX_H

void free_notation(rpn *);
rpn *get_postfix(token *);
rpn *add_notation(rpn *, char *);
operators *add_ops(operators *head, char *value, int priority);

#endif
