void strncpy(char *s, char *t, int n)
{
    while(*t && n > 0)
    {
        *s++ = *t++;
        n--;
    }

    while(n-- > 0) 
        *s = '\0';
}

void strncat(char *s, char *t, int n)
{
    while(*s) 
        s++;
    
    while(*t && n > 0)
    {
        *s++ = *t++;
        n--;
    }

    while(n-- > 0)
        *s = '\0';
}

int strncmp(char *s, char *t, int n)
{ 
    for(; *s == *t && n > 0; s++, t++, n--)
        if(*s == '\0')
            return 0;
    return *s-*t;
}

