#include <stdio.h>

int main()
{
    int c,bl;
    bl = 0;

    while((c = getchar()) != EOF)
    {
        if(c == ' ') bl++;
        else 
        {
            if(bl >= 1)
            {
                putchar(' ');
                bl = 0;
            }
            putchar(c);
        }
    }
    return 0;
}
