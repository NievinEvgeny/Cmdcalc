void RemoveSpaces(char* source)
{
    char* i = source;
    char* j = source;
    while (*j != 0)
    {
        *i = *j++;
        if (*i != ' ')
        {
            i++;
        }
    }
    *i = 0;
}