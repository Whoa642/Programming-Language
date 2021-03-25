#include <string.h>

void ungets(char s[])
{
    int len = strlen(s);
    int i;
    for(i = len-1; i >= 0; i--)
        ungetch(s[i]);
}
