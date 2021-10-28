#include "../include/my_bc.h"

int check_consuctive_number(char *str, int index){

    if(is_digit(str[index-1]) == 0 && is_digit(str[index+1]) == 0)
        return 1;
    else
        return 0; 
}

int count_tokens(char *formula){

    int counter = 0,
        index = 0;

    while(formula[index]){

        if(formula[index] == ' ')
            counter++;

        index++;
    }

    return counter+1;
}

token *get_token_attribute(token *token){

    int index = 0,
        current = 0;

    while(current < token->token_count){
        switch(token->tokens[current][0]){
            case '+':
                my_strcpy(token->token_type[index], ADD);
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
                my_strcpy(token->token_type[index],MOD);
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
                if(is_digit(token->tokens[current][0]) == 1){
                    my_strcpy(token->token_type[index], VAL);
                    token->priority[index] = PRIORITY_FIVE;
                }else{
                    return NULL;
                }
        } 
        index++;
        current++;
    }
    return token;
}

token *get_tokens(char *formula, token *token){

    int index = 0,
        cur = 0,
        i = 0;

    char* new_token = malloc(sizeof(char)*MAX_STR_LEN);

    while(formula[index] != '\0'){
        while(formula[index] != ' ' && formula[index] != '\0'){
            new_token[i] = formula[index];
            index++;
            i++;
        }
        new_token[i] = '\0';
        my_strcpy(token->tokens[cur], new_token);

        cur++;
        index++;
        i = 0;
    }

    return token;
}

//print tokens
void print_tokens(token *token)
{
    int i = 0;
    printf("\n Tokens: ");
    while(i < token->token_count){
        printf("%s pr: %d => ", token->tokens[i], token->priority[i]);
        i++;
    }
    printf("\n");
}

token *get_lexer(char *formula)
{

    printf("Formula: %s\n", formula);
    token *new_token = malloc(sizeof(token)*1);

    if((new_token->token_count = count_tokens(formula)) == -1)
        return NULL;

    new_token->tokens = malloc(sizeof(char*)*new_token->token_count);
    new_token->token_type = malloc(sizeof(char*)*new_token->token_count);
    new_token->priority = malloc(sizeof(int)*new_token->token_count);

    for(int i = 0 ; i < new_token->token_count; i++){
        new_token->token_type[i] = malloc(sizeof(char));
        new_token->tokens[i] = malloc(sizeof(char)*MAX_TYPE_LEN);
    }

    new_token = get_tokens(formula, new_token);
    new_token = get_token_attribute(new_token);

    if(!new_token)
        return NULL;

    return new_token;
}

