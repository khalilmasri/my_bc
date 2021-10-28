#include "../include/my_bc.h"

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

    token *lexer = malloc(sizeof(token) * 1);
    rpn *rpn = NULL;

    char* formula = add_whitespace(argv[1]);

    if(check_formula(formula) == 1){

        lexer = get_lexer(formula);

        rpn = get_postfix(lexer);

        if(solving_tree(rpn, lexer) == 1){
            printf("result: %d\n", rpn->result);
        }
    }
    free_notation(rpn);
    free(formula);
    free_lexer(lexer);

    return 0;
}
