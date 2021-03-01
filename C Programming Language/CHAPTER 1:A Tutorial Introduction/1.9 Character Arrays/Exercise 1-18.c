#include <stdio.h>
#define MAX 1000
int getline(char s[],int maxline);
int delete(char s[]);

int main()
{
    int len; char line[MAX];

    while((len = getline(line,MAX)) > 0)
        if(delete(line) > 0) printf("%s",line);
    return 0;
}

int getline(char s[],int lim)
{
    int c,i;

    for(i = 0; i < lim-2 && (c = getchar()) != EOF && c != '\n'; ++i) s[i] = c;
    if(c == '\n') s[i++] = c;
    s[i] = '\0';

    return i;
}

int delete(char s[])
{
    int i = 0;
    while(s[i] != '\n') ++i;
    --i;
    while(i >= 0 && (s[i] == '\t' || s[i] == ' ')) --i;
    if(i >= 0)
    {
        ++i;
        s[i] = '\n';
        ++i;
        s[i] = '\0';
    }
    return i;
}
