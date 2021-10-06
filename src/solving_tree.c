#include "../include/my_bc.h"

int get_last_priority(token *token){
    
    int index = token->token_count-1,
        flag_index = -1,
        max_priority = 1;

    while(token->priority[index]){

        if(max_priority == token->priority[index])
            return index;

        if(flag_index == -1 && index-1 == 0 && max_priority != 5){
            max_priority++;
            index = token->token_count-1;
        }

        index--;
    }

    return flag_index;
}

int order_priority(token *token){
    
    int last_max_priority;

    last_max_priority = get_last_priority(token);
 
    return last_max_priority;
}

int solving_tree(token *token){
    
    return order_priority(token);
    
}
