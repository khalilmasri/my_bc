#include "../include/my_bc.h"

//math functions to work from pointers
int mult(int a, int b)
{
    return a * b;
}

int divide(int a, int b)
{
    return (a - (a % b)) / b;
}

int mod(int a, int b)
{
    return a % b;
}

int add(int a, int b)
{
    return a + b;
}

int sub(int a, int b)
{
    return a - b;
}

void print_stack(char **stack, int stack_size)
{

    int i;

    for (i = 0; i < stack_size; i++)
    {
        printf("%s ", stack[i]);
    }
    printf("\n");
}

int restack(char **stack, char type, int i, int count)
{
    int (*funcPtr)(int, int);
    if (type == '*')
        funcPtr = mult;
    else if (type == '/')
        funcPtr = divide;
    else if (type == '%')
        funcPtr = mod;
    else if (type == '+')
        funcPtr = add;
    else
        funcPtr = sub;

    int j = i - 2;

    if(funcPtr == divide && atoi(stack[i-1]) == 0){
        printf("Numbers can't be devided on 0.\n");
        return 0;
    }

    stack[j] = my_itoa((*funcPtr)(atoi(stack[i - 2]), atoi(stack[i - 1])));
    //printf("%s, \n", stack[j]);
    i++, j++;
    while (i < count)
    {
        stack[j] = stack[i];
        i++;
        j++;
    }
    return 1;
}

char *init_stack(rpn *rpn, char **stack, int count)
{
    int i = 0;
    for (i = 0; i < count; i++)
    {
        stack[i] = malloc(sizeof(char) * MAX_STR_LEN);
    }
    i = 0;
    while (rpn != NULL)
    {
        my_strcpy(stack[i], rpn->token);
        rpn = rpn->next;
        i++;
    }
    return *stack;
}

int solving_tree(rpn *rpn, token *token)
{
    int count = token->token_count;
    char *stack[count];
    int i = 0;

    *stack = init_stack(rpn, stack, count);
    /* printf("print inititalized and filled stack\n"); */
    /* print_stack(stack, count); */

    while (count > 1) // count will count down til 1 string remains;
    {
        while (i < count) // i will count up til count;
        {
            if (is_op(stack[i][0]) == 1)
            {
                if(restack(stack, stack[i][0], i, count) == 0)
                    return 0;
                count -= 2, i = 0;
                /* print_stack(stack, count); */
            }
            else
            {
                i++;
            }
        }
    }
    rpn->result = atoi(stack[0]);
    return 1;
}
