#include <stdio.h>

int main(void)
{
    int c;
    int isBlank = 0;
    while((c = getchar()) != EOF)
    {
        if(c != ' ')
        {
            if(isBlank)
            {
                putchar(' ');
                isBlank = 0;
            }
            putchar(c);
        }
        if(c == ' ')
        {
            isBlank = 1;
        }
    }

    return 0;
}


