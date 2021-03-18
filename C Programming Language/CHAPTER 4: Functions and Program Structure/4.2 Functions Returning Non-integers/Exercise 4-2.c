#include <ctype.h>

double atof(char s[])
{
    double val,power;
    int i,j,sign,num;

    for(i = 0; isspace(s[i]); i++);

    sign = (s[i] == '-') ? -1 : 1;
    if(s[i] == '+' || s[i] == '-') i++;
    
    for(val = 0.0; isdigit(s[i]); i++)
        val = 10.0*val+(s[i]-'0');
    
    if(s[i] == '.') i++;

    for(power = 1.0; isdigit(s[i]); i++)
    {
        val = 10.0*val+(s[i]-'0');
        power *= 10.0;
    }
  
    if(s[i] == 'e' || s[i] == 'E')
    {
        i++;
        if(s[i] == '-' || s[i] == '+')
        {
            
            for(j = i+1,num = 0; isdigit(s[j]); j++) num = 10*num+(s[j]-'0');

            if(s[i] == '-')
            {
                while(num--) power *= 10.0;
            }
            else 
            {
                while(num--) power /= 10.0;
            }
        }
    }
    return sign*val/power;
}
