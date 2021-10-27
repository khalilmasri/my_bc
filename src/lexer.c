#include "../include/my_bc.h"

int check_consuctive_number(char *str, int index){

    if(is_digit(str[index-1]) == 0 && is_digit(str[index+1]) == 0)
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

token *get_token_attribute(char c, token *token, int index){

    switch(c){
        case '+':
            my_strcpy(token->token_type[index],ADD);
            token->priority[index] = PRIORITY_THREE;
            break;
        case '-':
            my_strcpy(token->token_type[index],SUB);
            token->priority[index] = PRIORITY_THREE;
            break;
        case '*':
            my_strcpy(token->token_type[index],MULT);
            token->priority[index] = PRIORITY_TWO;
            break;
        case '/':
            my_strcpy(token->token_type[index],DIV);
            token->priority[index] = PRIORITY_TWO;
            break;
        case '%':
            my_strcpy(token->token_type[index],SUB);
            token->priority[index] = PRIORITY_TWO;
            break;
        case '(':
            my_strcpy(token->token_type[index], OPEN_PAR);
            token->priority[index] = PRIORITY_FOUR;
            break;
        case ')':
            my_strcpy(token->token_type[index], CLOSE_PAR);
            token->priority[index] = PRIORITY_ONE;
            break;
        default:
            if(is_digit(c) == 0){
                my_strcpy(token->token_type[index],VAL);
                token->priority[index] = PRIORITY_FIVE;
            }else 
                return NULL;
            break;
    }

    return token;
}

token *get_tokens(char *argv, token *token){

    int index = 0,
        cur = 0;

    while(argv[index]){
        if(argv[index] != ' '){
            token->tokens[cur][0] = argv[index];
            token = get_token_attribute(argv[index], token, index);

            if(token == NULL)
                return NULL;

            printf("token: %c type: %s Priority: %d\n", token->tokens[cur][0], token->token_type[cur], token->priority[cur]);
            cur++;
        }

        index++;
    }

    return token;
}

token *get_lexer(char *argv){

    token *new_token = malloc(sizeof(token)*1);

    if((new_token->token_count = count_tokens(argv)) == -1)
         return NULL;
    
    new_token->tokens = malloc(sizeof(char*)*new_token->token_count);
    new_token->token_type = malloc(sizeof(char*)*new_token->token_count);
    new_token->priority = malloc(sizeof(int)*new_token->token_count);

    for(int i = 0 ; i < new_token->token_count; i++){
        new_token->token_type[i] = malloc(sizeof(char));
        new_token->tokens[i] = malloc(sizeof(char)*MAX_TYPE_LEN);
    }

    new_token = get_tokens(argv, new_token);

    if(!new_token)
        return NULL;

    return new_token;
}

