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

void itob(int n,char s[],int b)
{
    char base[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int i,sign;
    sign = n; i = 0;
    
    do
    {
        s[i++] = base[abs(n%b)];
    }while((n /= b));
    
    if(sign < 0) s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}
