#include <stdio.h>

int main()
{
    printf("hello, world\c"); /* undefined behavior */
    return 0;
}