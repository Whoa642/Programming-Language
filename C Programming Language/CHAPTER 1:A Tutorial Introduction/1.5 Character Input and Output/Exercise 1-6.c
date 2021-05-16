#include <stdio.h>

int main()
{
    int c;
    while(c = getchar() != EOF) // c is assigned 0 if getchar() returns EOF or 1 if not
        printf("%d\n",c);
    
    return 0;
}
