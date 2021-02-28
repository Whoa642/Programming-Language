#include <stdio.h>
#define IN 1
#define OUT 0

int main()
{
    int c,nc,state;

    nc = 0;
    state = OUT;
    while((c = getchar()) != EOF)
    {
        if(c == '\n' || c == ' ' || c == '\t') 
        {
            if(nc) putchar('\n');
            nc = 0;
            state = OUT;
        }
        else if(state == OUT)
        {
            putchar(c);
            nc++;
            state = IN;
        }
        else if(state == IN)
        {
            nc++;
            putchar(c);
        }
    }
}
