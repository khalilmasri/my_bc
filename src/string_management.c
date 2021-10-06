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

int my_is_digit(char c)
{
    if (c >= '0' && c <= '9')
        return 0;
    else
        return 1;

}