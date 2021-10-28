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

//function to add value to rpn beginning of list
rpn *add_notation(rpn *head, char *value)
{
    rpn *new_node = malloc(sizeof(rpn));
    new_node->token = malloc(sizeof(char) * (strlen(value) + 1));

    if(head == NULL)
    {
        strcpy(new_node->token, value);
        new_node->next = NULL;
        //printf("%s notation added to empty\n", new_node->token);
        return (new_node);
    }
    else
    {
        strcpy(new_node->token, value);
        new_node->next = head;
        //printf("%s notation added to head\n", new_node->token);
        return (new_node);
    }
}

operators *add_ops(operators *head, char *value, int priority)
{
    operators *new_node = malloc(sizeof(operators));
    new_node->token = malloc(sizeof(char) * (strlen(value) + 1));

    if(head == NULL)
    {
        strcpy(new_node->token, value);
        new_node->priority = priority;
        new_node->next = NULL;
        //printf("%s op added to empty\n", new_node->token);
        return (new_node);
    }
    else
    {
        strcpy(new_node->token, value);
        new_node->priority = priority;
        new_node->next = head;
        //printf("%s op added to head\n", new_node->token);
        return (new_node);
    }
}

operators *remove_ops(operators *head)
{
    //if head is null, return null
    if(head == NULL)
    {
        printf("ops list is empty\n");
        return (NULL);
    }
    //delete and free memory of head node and return next node
    operators *temp = head;
    head = head->next;
    temp->next = NULL;
    free(temp->token);
    free(temp);
    return head;
}

void free_ops(operators *head)
{
    //if head is null, return null
    if(head == NULL)
    {
        return;
    }
    while(head)
    {
        head = remove_ops(head);
    }
    //printf("Ops list freed\n");
}

rpn *reverse_notation(rpn *head)
{

    if(head == NULL) return NULL;
    if(head->next == NULL) return head;

    rpn *reversed = reverse_notation(head->next);

    head->next->next = head;
    head->next = NULL;

    return reversed;
}

void print_ops(operators *head)
{
    if (head == NULL)
    {
        printf("ops is empty\n");
        return;
    }
    printf("\nOps list: ");
    while (head != NULL)
    {
        printf("%s ", head->token);
        head = head->next;
    }
    printf("\n");
}
void print_notation(rpn *head)
{
    if(head == NULL)
    {
        printf("Notation is empty\n");
        return;
    }

    printf("Postfix notation:");
    while (head)
    {
        printf("%s ", head->token);
        head = head->next;
    }
    printf("\n");

}

int search_stack(operators *ops, int priority){

    if(!ops)
        return 0;

    while(ops){
        if(ops->priority == priority)
            return 1;
        else if(ops->priority == 4)
            return 0;
        ops = ops->next;
    }

    return 0;
}

rpn *get_postfix(token *token)
{
    rpn *notations = malloc(sizeof(rpn));
    notations = NULL;
    operators *ops = malloc(sizeof(operators));
    ops = NULL;
    bool mod = false;
    int pars = 0;

    int i = 0;

    while (i < token->token_count)
    {
        if (token->priority[i] == PRIORITY_FIVE)
            notations = add_notation(notations, token->tokens[i]);

        else if (token->priority[i] != PRIORITY_ONE)
        {
            if((search_stack(ops, token->priority[i])) == 1){
                while((search_stack(ops, token->priority[i])) == 1){
                    if(strcmp(token->token_type[i],MOD) == 0){
                        notations = add_notation(notations, token->tokens[i]);
                        mod = true;
                        break;
                    }
                    notations = add_notation(notations, ops->token);
                    ops = remove_ops(ops);
                }
                if(mod == false) 
                    ops = add_ops(ops, token->tokens[i], token->priority[i]);
                else
                    mod = false;
            }
            else{
                ops = add_ops(ops, token->tokens[i], token->priority[i]);
            }
        }
        else
        {
            pars++; //take closed parenthesis off token count
            while(ops->priority != 4){
                if (ops == NULL)
                {
                    print_error("parentheses");
                    return NULL;
                }
                notations = add_notation(notations, ops->token);
                ops = remove_ops(ops);

            }
            pars++; //take open parenthesis off token
            ops = remove_ops(ops);
        }
        i++;
    }
    while (ops != NULL)
    {
        notations = add_notation(notations, ops->token);
        ops = remove_ops(ops);
    }
    free_ops(ops);
    notations = reverse_notation(notations);
    print_notation(notations);
    token->token_count -= pars;
    return notations;
}
