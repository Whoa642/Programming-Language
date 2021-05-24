#include <stdio.h>
#define MAX 1000

int getline(char s[],int maxline);
void reverse(char s[]);

int main()
{
    char line[MAX]; int len;

    while((len = getline(line,MAX)) > 0)
    {
        reverse(line);
        printf("%s",line);
    }

    return 0;
}

int getline(char s[],int lim)
{
    int c,i;

    for(i = 0; i < lim-2 && (c = getchar()) != EOF && c != '\n'; i++) 
        s[i] = c;

    if(c == '\n') 
        s[i++] = c;
    s[i] = '\0';
    
    return i;
}

void reverse(char s[])
{
    char tmp;
    int i,j;

    i = 0;
    while(s[i] != '\0')
        i++;
    
    if(s[--i] == '\n') 
        i--;

    for(j = 0; j < i; i--,j++)
    {
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }
}
