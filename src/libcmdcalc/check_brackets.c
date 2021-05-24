int check_brackets(char* expression)
{
    int open = 0, close = 0;
    while (*expression)
    {
        if (*expression == '(')
        {
            open++;
        }
        if (*expression == ')')
        {
            close++;
        }
        expression++;
    }
    if (open == close)
    {
        return 0;
    }
    return 1;
}