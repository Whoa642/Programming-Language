#include <string.h>
void _reverse(char s[],int left,int high)
{
    int c;
    if(left >= high) 
        return;

    c = s[left];
    s[left] = s[high];
    s[high] = c;
    _reverse(s,left+1,high-1);
}

void reverse(char s[])
{
    _reverse(s,0,strlen(s)-1);
}
