#include "calculation.h"
#include <stdio.h>
#include <stdlib.h>

void check_operations_sequence(char* expression, int i)
{
    if ((*(expression + i) == '+') || (*(expression + i) == '-') || (*(expression + i) == '*') || (*(expression + i) == '/'))
    {
        printf("Operations placed incorrectly\n\n");
        exit(-1);
    }
}

float calculation(char* expression)
{
    int i = 0;
    return last_priority(expression, &i);
}

float last_priority(char* expression, int* i)
{
    float result = first_priority(expression, i);
    while (*(expression + *i) == '+' || *(expression + *i) == '-')
    {
        switch (*(expression + *i))
        {
        case '+':
            *i += 1;
            check_operations_sequence(expression, *i);
            result += first_priority(expression, i);
            break;
        case '-':
            *i += 1;
            check_operations_sequence(expression, *i);
            result -= first_priority(expression, i);
            break;
        }
    }
    return result;
}

float first_priority(char* expression, int* i)
{
    float divider;
    float result = brackets_priority(expression, i);
    while (*(expression + *i) == '*' || *(expression + *i) == '/')
    {
        switch (*(expression + *i))
        {
        case '*':
            *i += 1;
            check_operations_sequence(expression, *i);
            result *= brackets_priority(expression, i);
            break;
        case '/':
            *i += 1;
            check_operations_sequence(expression, *i);
            divider = brackets_priority(expression, i);
            if (divider != 0)
            {
                result /= divider;
            }
            if (divider == 0)
            {
                printf("The expression contains a division by zero\n");
                exit(-1);
            }
            break;
        }
    }
    return result;
}

float brackets_priority(char* expression, int* i)
{
    float result;
    if (*(expression + *i) == '(')
    {
        *i += 1;
        result = last_priority(expression, i); // recursion for expression in brackets
        *i += 1;
    }
    else
    {
        result = take_number(expression, i);
    }
    return result;
}

float take_number(char* expression, int* i)
{
    if ((*(expression + *i) < '0') || (*(expression + *i) > '9'))
    {
        printf("Operations placed incorrectly\n\n");
        exit(-1);
    }
    float result = 0;
    float factor = 1;
    short sign = 1;
    while (*(expression + *i) == '-')
    {
        sign *= -1;
        *i += 1;
    }
    while (*(expression + *i) >= '0' && *(expression + *i) <= '9')
    {
        result = 10 * result + (*(expression + *i) - '0');
        *i += 1;
    }
    if (*(expression + *i) == '.')
    {
        *i += 1;
        while (*(expression + *i) >= '0' && *(expression + *i) <= '9')
        {
            factor *= 0.1;
            result = result + (*(expression + *i) - '0') * factor;
            *i += 1;
        }
    }
    return result * sign;
}