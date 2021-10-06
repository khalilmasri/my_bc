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
        printf("parentheses must be properly closed\n");
    

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

        index++;
    }

    sum = count_open - count_close;
    return sum;
}