#include "../include/my_bc.h"

int main(int argc, char **argv){

    if(argc < 2){
        print_error("usage");
        return 1;
    }

    if(count_open_closed(argv[1]) != 0){
        print_error("parentheses");
        return 1;
    }

    token *new_lexer = malloc(sizeof(token)*1);

    if((new_lexer = get_lexer(argv[1])))
        printf("Success\n");
    else
        printf("Error\n");

}
