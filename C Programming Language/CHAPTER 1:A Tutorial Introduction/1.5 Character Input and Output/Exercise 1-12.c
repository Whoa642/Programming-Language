#include <stdio.h>
#define IN 1
#define OUT 0
#define CHAR 'A'

int main()
{
    int c,last = CHAR;
    int state = OUT;
    while((c = getchar()) != EOF)
    {
        if(state == IN)
            if(last != '\t' && last != ' ' && last != '\n')
                putchar(last);
        if(c == '\t' || c == ' ' || c == '\n')
        {
            state = OUT;
            if(last != '\t' && last != ' ' && last != '\n')
                putchar('\n');
        }
        else if(state == OUT)
            state = IN;

        last = c;
    }
    return 0;
}
