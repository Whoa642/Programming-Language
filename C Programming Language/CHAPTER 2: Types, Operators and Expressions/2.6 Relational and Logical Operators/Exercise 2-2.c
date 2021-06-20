#include <stdio.h>
#include <stdbool.h>
#define MAX 1000

int main(void)
{
    bool ok;
    int i,c;
    char line[MAX];

    ok = true;
    i = 0;
    while(ok)
    {
        if(i >= MAX-2)
            ok = false;
        else if((c = getchar()) == '\n')
            ok = false;
        else if(c == EOF)
            ok = false;
        else
            line[i++] = c;
    }

    return 0;
}
