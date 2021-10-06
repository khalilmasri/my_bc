#include "../include/my_bc.h"

int check_consuctive_number(char *str, int index){

    if(my_is_digit(str[index-1]) == 0 && my_is_digit(str[index+1]) == 0)
        return 1;
    else
        return 0; 
}

int count_tokens(char *argv){

    int counter = 0,
        index = 0;

    while(argv[index]){
        
        if(argv[index] != ' ')
            counter++;
        else if(check_consuctive_number(argv, index) == 1)
            return -1;

        index++;
    }

    return counter;
}


token *get_lexer(char *argv){

    token *new_token = malloc(sizeof(token)*1);

    if(count_tokens(argv) != -1)
        new_token->token_count = count_tokens(argv); 
    else
         return NULL;
       
}