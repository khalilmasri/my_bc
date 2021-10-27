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
    printf("\ninput string: %s\n\n", argv[1]);
    //function to convert to Reverse Polish Notation needed here to be able to evaluate
    //e.g "5+65*7" -> "5 65 * 7 +" (probably add whitespaces first in order to seperate the numbers)

    token *new_lexer = malloc(sizeof(token) * 1);

    char* formula = add_whitespace(argv[1]);

    if ((new_lexer = get_lexer(formula)))
        printf("Success\n");
    else
        printf("Error\n");


    if(get_postfix(new_lexer) != NULL)
        printf("Success\n");
    else
        printf("Error\n");
    /* printf("%d last max priority\n", solving_tree(new_lexer)); */
}
