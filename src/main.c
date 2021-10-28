#include "../include/my_bc.h"

//function to free the notation list
void free_notation(rpn *head)
{

    rpn *temp;

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp->token);
        free(temp);
    }
}

int main(int argc, char **argv)
{

    if (argc < 2)
    {
        print_error("usage");
        return 1;
    }

    if (count_open_closed(argv[1]) != 0)
    {
        print_error("parentheses");
        return 1;
    }
    printf("\nInput string: %s\n\n", argv[1]);

    token *new_lexer = malloc(sizeof(token) * 1);
    rpn *rpn = NULL;
    char* formula = add_whitespace(argv[1]);

    if ((new_lexer = get_lexer(formula)))
        printf("Success Lexer\n");
    else
        printf("Error Lexer\n");

    
    if((rpn = get_postfix(new_lexer)) != NULL)
    {
        printf("Success Postfix\n");
    }
    else
        printf("Error Postfix\n");

    printf("result: %d\n", solving_tree(rpn, new_lexer));
    free_notation(rpn);



    return 0;
}
