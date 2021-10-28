#include "../include/my_bc.h"

int my_memset(char *buffer, char c, int size)
{
    int index = 0;

    while (index < size){
        buffer[index] = c;
        index += 1;
    }
    
    return index;
}

char *my_strcpy(char *dest, char *src){
    while (*src != '\0'){
        *dest++ = *src++;
    }
    *dest = '\0';

    return dest;
}

char *my_itoa(int value)
{
    int len;
    long nbr;
    char *pointer = NULL;
    char *base_string = "0123456789ABCDEF";

    if (value == 0)
    {
        pointer[0] = '0';
        return pointer;
    }
    len = 0;
    nbr = value;
    while (nbr) //this loop sets the length of the string
    {
        nbr /= 10;
        len += 1;
    }
    nbr = value;
    if (nbr < 0) //this increases the length of the string to add the '-' character
    {
        len += 1;
        nbr *= -1;
    }
    if (!(pointer = (char *)malloc(sizeof(char) * len + 1)))
        return (NULL);
    pointer[len] = '\0'; //sets the last character to NULL
    while (nbr)          //This loop fills the character string from the end to the beginning.
    {
        pointer[--len] = base_string[nbr % 10];
        nbr /= 10;
    }
    if (value < 0) //Sets the first character to '-' if the value is negative
        pointer[0] = '-';

    return (pointer);
}

long my_atoi(char *number_string, int size)
{
    int index = 0;
    long res = 0;
    while (index < size && number_string[index])
    {
        if (number_string[index] >= '0' && number_string[index] <= '9')
        {
            res *= 10;
            res += number_string[index] - '0';
        }
        index++;
    }
    return res;
}

int my_strcmp(char *ptr1, char *ptr2)
{
    int i = 0;
    while ((ptr1[i] != '\0') || (ptr2[i] != '\0'))
    {
        if (ptr1[i] > ptr2[i])
            return 1;
        if (ptr1[i] < ptr2[i])
            return -1;
        i++;
    }

    return 0;
}

//function to check if is digit
int is_digit(char c) {
    if (c >= '0' && c <= '9') 
    {
        return 1;
    }
    return 0;
}

//function to check if is operator
int is_op(char c) {
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
        if(formula[i] == ' ')
            while(formula[i] == ' ')
                i++;
        
        if (is_digit(formula[i]) == 1 && is_digit(formula[i-1]) == 1) 
        {
            new_formula[j] = formula[i];
            i++;
            j++;
        }
        else
        {
            new_formula[j] = ' ';
            j++;
            new_formula[j] = formula[i];
            j++;
            i++;
        }
    }
    new_formula[j] = '\0';
    return new_formula;
}

