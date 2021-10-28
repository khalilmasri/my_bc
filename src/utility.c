#include "../include/my_bc.h"

void print_error(char *error){

    if(my_strcmp(error, "usage") == 0){
        printf("The program:\n");
        printf("must only contain the operators +, -, *, /, and %%\n");
        printf("must only have integer values\n");
        printf("can contain parentheses, but each group must be properly closed\n");
        printf("can contain spaces\n");
    }

    if(my_strcmp(error, "parentheses") == 0)
        printf("parentheses must be properly closed and have an input.\n");
    

}

int is_operator(char c){
    switch(c){
        case '+':
            return 1;
        case '-':
            return 1;
        case '/':
            return 1;
        case '*':
            return 1;
        case '%':
            return 1;
        case '(':
            return 0;
        case ')':
            return 0;
        default:
            if(is_digit(c) == 1)
                return 0;
            else 
                return 1;
    }
}

int check_formula(char* formula){

    int index = 0;

    while(formula[index]){
        while(is_digit(formula[index]) == 1 || formula[index] == ' '){
            index++;
            if(formula[index] == '\0')
                return 1;
        }

        if((is_operator(formula[index])) == 1 && (is_operator(formula[index+2])) == 1){
            printf("Syntax error.\n");
            return 0;
        }
        index++;
    }

    return 1;
}

int count_open_closed(char *argv){

    int count_open = 0,
        count_close = 0,
        sum,
        index = 0;

    while(argv[index] != '\0'){
        if(argv[index] == '(')
            count_open++;
        
        if(argv[index] == ')')
            count_close++;

        if(argv[index] == '(' && argv[index+1] == ')')
            return 1;
        index++;
    }

    sum = count_open - count_close;
    return sum;
}
