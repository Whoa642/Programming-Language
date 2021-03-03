#include <stdio.h>
#include <limits.h>

int main()
{   //standard headers 
    printf("min of signed char:%d\n",CHAR_MIN);
    printf("max of signed char:%d\n",CHAR_MAX);
    printf("min of signed short:%d\n",SHRT_MIN);
    printf("max of signed short:%d\n",SHRT_MAX);
    printf("min of signed int:%d\n",INT_MIN);
    printf("max of signed int:%d\n",INT_MAX);
    printf("min of signed long:%ld\n",LONG_MIN);
    printf("max of signed long:%ld\n",LONG_MAX);

    putchar('\n');
    printf("max of unsigned char:%u\n",UCHAR_MAX);
    printf("max of unsigned short:%u\n",USHRT_MAX);
    printf("max of unsigned int:%u\n",UINT_MAX);
    printf("max of unsigned long:%lu\n",ULONG_MAX);

    putchar('\n');
    //direct computation
    char c = (1 << 7);
    short s = (1 << 15);
    int i = (1 << 31);
    long l = (1 << 31);

    printf("min of signed char:%d\n",c);
    printf("max of signed char:%d\n",~c); 
    printf("min of signed short:%d\n",s); 
    printf("max of signed short:%d\n",~s);
    printf("min of signed int:%d\n",i);
    printf("max of signed int:%d\n",~i);
    printf("min of signed long:%ld\n",l); 
    printf("max of signed long:%ld\n",~l); 

    putchar('\n');
    unsigned char uc = -1;
    unsigned short us = -1;
    unsigned int ui = -1;
    unsigned long ul = -1;
    printf("max of unsigned char:%u\n",uc);
    printf("max of unsigned short:%u\n",us); 
    printf("max of unsigned int:%u\n",ui); 
    printf("max of unsigned long:%lu\n",ul); 
  
    return 0;
}
