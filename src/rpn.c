#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//just going to try figure this code out seperate to the main program, to get the RPN to work
//then can go from there.

//function to check if is digit
int is_digit(char c) {
    if (c >= '0' && c <= '9') 
    {
        return 1;
    }
    return 0;
}

//function to check if is operator
int is_operator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%') 
    {
        return 1;
    }
    return 0;
}

//function to check for parenthesis
int is_par(char c) {
    if (c == '(' || c == ')') 
    {
        return 1;
    }
    return 0;
}

//function to add whitespace between operators and operands in the input string
char* add_whitespace(char* formula) 
{
    int i = 0;
    int j = 0;
    int len = strlen(formula);
    char* new_formula = malloc((sizeof(char) * strlen(formula) * 2) + 1);
    new_formula[j] = formula[i];
    i++;
    j++;
    while (i < len) 
    {
        if (is_digit(formula[i]) == 1 && is_digit(formula[i-1]) == 1) 
        {
            new_formula[j] = formula[i];
            j++;
        }
        else
        {
            new_formula[j] = ' ';
            j++;
        }
        new_formula[j] = formula[i];
        j++;
        i++;
    }
    new_formula[j] = '\0';
    return new_formula;
}

//function to convert to RPN
char* rpn(char* formula)
{
    char* spaced = malloc((sizeof(char) * strlen(formula) * 2) + 1);
    char* ret = malloc((sizeof(char) * strlen(formula) * 2) + 1);
    spaced = add_whitespace(formula);
    
    //convert spaced == "5 + 7 - ( 344 - 100 )" into ret == "5 7 + 344 100 - -"
    int i = 0;
    int j = 0;
    int len = strlen(spaced);
    int par_count = 0;

    while (i < len) 
    {
        



    return ret;
}

int main(int argc, char **argv) 
{
    if(argc != 2) {
        printf("Usage: %s <expression>\n", argv[0]);
        return 1;
    }
    char* ret = malloc((strlen(argv[1]) * 2) + 1);

    ret = rpn(argv[1]);
    printf("\nInput Formula: %s\n\n", argv[1]);
    printf("RPN of Formula: %s\n\n", ret);

    free(ret);
    return 0;

}

    