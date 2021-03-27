#include <string.h>
void reverse(char s[])
{
    int i,j,c;
    i = 0;
    i = (s[0] == '-') ? i+1 : i;

    for(j = strlen(s)-1; i < j; i++,j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void _itoa(int n,char s[],int idx)
{
    if(n < 0)
    {
        s[idx++] = '-';
        n = -n;
    }

    if(n == 0)
    {
        if(idx == 0) s[idx++] = '0';
        s[idx] = '\0';
        reverse(s);
        return;
    }

    s[idx] = (n%10)+'0';
    _itoa(n/10,s,idx+1);
}

void itoa(int n,char s[])
{
    _itoa(n,s,0);
}
