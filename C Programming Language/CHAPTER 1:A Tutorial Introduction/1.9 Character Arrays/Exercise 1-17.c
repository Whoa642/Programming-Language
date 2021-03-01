#include <stdio.h>
#define MAX 1000
#define LIMIT 80

int getline(char s[],int maxline);

int main()
{
    int c,len;
    len = 0;

    char line[MAX];
    while((len = getline(line,MAX)) > 0)
        if(len > LIMIT) printf("%s",line);
}

int getline(char s[],int lim)
{
    int c,i;

    for(i = 0; i < lim-2 && (c = getchar()) != EOF && c != '\n'; ++i) s[i] = c;
    if(c == '\n') s[i++] = c;
    s[i] = '\0';
    return i;
}
