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
        printf("Ops list is empty\n");
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

    rpn *prev, *current;

    if (head != NULL)
    {
        prev = head;
        current = head->next;
        head = head->next;
        prev->next = NULL;

        while (head)
        {
            head = head->next;
            current->next = prev;
            prev = current;
            current = head;
        }
        head = prev->next;
    }
    return head;
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
}
void print_notation(rpn *head)
{

    if(head == NULL)
    {
        printf("Notation is empty\n");
        return;
    }
    printf("\nNotation list: ");
    while (head != NULL)
    {
        printf("%s ", head->token);
        head = head->next;
    }
    printf("\n");
}

rpn *get_postfix(token *token)
{
    rpn *notations = malloc(sizeof(rpn));
    operators *ops = malloc(sizeof(operators));
    int pars = 0;
    
    int i = 0;

    while (i < token->token_count)
    {
        if (token->priority[i] == PRIORITY_FIVE)
        {
            notations = add_notation(notations, token->tokens[i]);
        }
        else if (token->priority[i] != PRIORITY_ONE)
        {
            if (token->priority[i] == ops->priority)
            {
                notations = add_notation(notations, ops->token);
                ops = remove_ops(ops);
                ops = add_ops(ops, token->tokens[i], token->priority[i]);
            }
            else
            {
                ops = add_ops(ops, token->tokens[i], token->priority[i]);
            }
        }
        else
        {
            pars++; //take closed parenthesis off token count
            while (ops->priority != 4)
            {
                notations = add_notation(notations, ops->token);
                ops = remove_ops(ops);
            }
            if (ops == NULL)
            {
                printf("Parenthesis not closed properly.\n");
                return NULL;
            }
            pars++; //take open parenthesis off token
            ops = remove_ops(ops);
        }
        i++;
    }
    while (ops->next != NULL)
    {
        notations = add_notation(notations, ops->token);
        ops = ops->next;
    }
    free_ops(ops);
    notations = reverse_notation(notations);
    token->token_count -= pars;
    return notations;
}
