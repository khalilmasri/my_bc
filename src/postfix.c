#include "../include/my_bc.h"

rpn *add_notation(rpn *head, char* value){

    rpn *new_node = malloc(sizeof(rpn));

    new_node->token = malloc(sizeof(char)*MAX_STR_LEN);

    my_strcpy(new_node->token, value);
    new_node->next = head;

    return new_node;
}

operators *add_ops(operators *head, char* value, int priority){

    operators *new_node = malloc(sizeof(operators));

    new_node->token = malloc(sizeof(char)*MAX_STR_LEN);

    my_strcpy(new_node->token, value);
    new_node->priority = priority;
    new_node->next = head;

    return new_node;
}

operators *remove_ops(operators *head){

    if(head == NULL){
        return NULL;
    }

    operators *temp = head;
    head = head->next;

    free(temp);
    return head;
}

rpn *reverse_notation(rpn *head){

    rpn *prev, *current;

    if(head != NULL){
        prev = head;
        current = head->next;
        head = head->next;
        prev->next = NULL;

        while(head){
            head = head->next;
            current->next = prev;
            prev = current;
            current = head;
        }

        head = prev->next;
    }

    return head;
}

void print_ops(operators *head){

    while(head){
        printf("Tokens: %s priority: %d\n", head->token, head->priority);
        head = head->next;
    }
}
void print_notation(rpn *head){

    while(head){
        printf("%s\n", head->token);
        head = head->next;
    }

    printf("\n");
}
rpn *get_postfix(token *head){

    rpn *notations = malloc(sizeof(rpn));
    operators *ops = malloc(sizeof(ops));

    int index = 0;

    while(index < head->token_count){
        if(head->priority[index] == 5)
            notations = add_notation(notations, head->tokens[index]);
        else if(head->priority[index] != 1){
            if(head->priority[index] == ops->priority){
                notations = add_notation(notations, ops->token);
                ops = remove_ops(ops);
                ops = add_ops(ops, head->tokens[index], head->priority[index]);
            }else{
                ops = add_ops(ops, head->tokens[index], head->priority[index]);
            }
        }else{
           while(ops->priority != 4){
                notations = add_notation(notations, ops->token);
                if((ops = remove_ops(ops))==NULL){
                    printf("Parenthasis are not closed properly.\n");
                    return NULL;
                }
           } 
            ops = remove_ops(ops);
        }
        
        index++;
    }

    while(ops->next != NULL){
        notations = add_notation(notations, ops->token);
        ops = ops->next;
    }

    notations = reverse_notation(notations);
    print_notation(notations);
    return notations;
}
