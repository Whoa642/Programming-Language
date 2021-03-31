int getop(char s[]) 
{
    int i,c;
    static int l = 0;

    if(l)
    {
        c = l;
        l = 0;
    }

    while((s[0] = c = getch()) == ' ' || c == '\t');
    s[1] = '\0'; 
    i = 0;

    if(!isdigit(c) && c != '.') return c;

    if(isdigit(c)) 
        while(isdigit(s[++i] = c = getch()));

    if(c == '.') 
        while(isdigit(s[++i] = c = getch()));
    
    s[i] = '\0';
    if(c != EOF) l = c;
    return NUMBER;
}
