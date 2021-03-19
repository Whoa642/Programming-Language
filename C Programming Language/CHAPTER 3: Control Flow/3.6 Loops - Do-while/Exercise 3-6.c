#define abs(x) ((x) > 0 ? (x) : (-x))

void reverse(char s[])
{
    int i,j;
    for(i = 0, j = strlen(s)-1; i < j; i++,j--)
    {
        char t = s[i];
        s[i] = s[j];
        s[j] = t;
    }
}

void itoa(int n,char s[],int b)
{
    int i,sign;
    sign = n; i = 0;
    
    do
    {
        s[i++] = (abs(n%10))+'0';
    }while((n /= 10));
    
    if(sign < 0) s[i++] = '-';
    while(i < b) s[i++] = ' ';
    s[i] = '\0';
    reverse(s);
}
