#include <libcmdcalc/calculation.h>
#include <libcmdcalc/check_brackets.h>
#include <libcmdcalc/format_expression.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    if (argc > 2)
    {
        printf("A mathematical expression must be enclosed in quotation marks\n");
        return -1;
    }
    if (argc == 1)
    {
        printf("No mathematical expression\n");
        return -1;
    }
    RemoveSpaces(argv[1]);
    char* expression = argv[1];
    if (strspn(expression, "0123456789()-+*/.") != strlen(expression))
    {
        printf("Incorrect symbols in expression\n");
        return -1;
    }
    if (check_brackets(expression) == -1)
    {
        printf("Brackets placed incorrectly\n");
        return -1;
    }
    printf("\n%s = ", expression);
    printf("%f\n\n", calculation(expression));
    return 0;
}