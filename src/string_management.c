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

char *my_itoa(char *dest, unsigned int number, int size, int base)
{
    const char symbols[] = "0123456789abcdef";
    my_memset(dest, '0', size - 1);
    dest[size - 1] = '\0';
    size -= 2;
    while (number)
    {
        dest[size] = symbols[number % base];
        number /= base;
        size--;
    }
    return dest;
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

