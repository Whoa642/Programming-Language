int buf;

int getch(void) 
{
    int c;
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
