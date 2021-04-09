int strend(char *s, char *t)
{
    char *ps = s;
    char *pt = t;

    while(*s) s++;
    while(*t) t++;

    for(; *s == *t; s--, t--)
        if(ps == s || pt == t)
            break;
    if(*s == *t && pt == t && *t != '\0')
        return 1;
    return 0;
}
