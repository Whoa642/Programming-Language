char buf;

int getch(void) 
{
    char c;
    if(buf) c = buf; 
    else c = getchar();
    buf = 0;

    return c;
}

void ungetch(int c)
{
    if(buf) printf("ungetch: too many characters\n");
    else buf = c;
}
