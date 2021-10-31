#include "../include/my_bc.h"

void print_error(char *error)
{
    if (my_strcmp(error, "usage") == 0)
    {
        printf("The program:\n");
        printf("must only contain the operators +, -, *, /, and %%\n");
        printf("must only have integer values\n");
        printf("can contain parentheses, but each group must be properly closed\n");
        printf("can contain spaces\n");
    }

    if (my_strcmp(error, "parentheses") == 0)
        printf("Parentheses must be properly closed and surround a valid equation.\n");
}

// int is_operator(char c)
// {
//     switch (c)
//     {
//     case '+':
//         return 1;
//     case '-':
//         return 1;
//     case '/':
//         return 1;
//     case '*':
//         return 1;
//     case '%':
//         return 1;
//     case '(':
//         return 0;
//     case ')':
//         return 0;
//     default:
//         if (is_digit(c) == 1)
//             return 0;
//         else
//             return 1;
//     }
// }

int check_formula(char *formula)
{
    int i = 0, con_ops = 0; //inc i by 2 because whitespaces

    while (formula[i])
    {
        while (is_digit(formula[i]) == 1) 
        {
            i+=2;
            if (formula[i] == '\0')
                return 1;
        }
        if (is_char(formula[i]) == 1)
        {
            printf("Error: Syntax Error.\n");
            return 0;
        }
        if (is_op(formula[i]) == 1 && is_op(formula[i + 2]) == 1)
        {
            con_ops++;
        }
        else
            con_ops = 0;

        if (con_ops > 1)
        {
            printf("Syntax error.\n");
            return 0;
        }
        i+=2;
    }
    return 1;
}

int count_open_closed(char *argv)
{
    int count_open = 0,
        count_close = 0,
        sum,
        index = 0;

    while (argv[index] != '\0')
    {
        if (argv[index] == '(')
            count_open++;

        if (argv[index] == ')')
            count_close++;

        if (argv[index] == '(' && argv[index + 1] == ')')
            return 1;
        index++;
    }
    sum = count_open - count_close;
    return sum;
}
