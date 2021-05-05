#include <stdarg.h>

void minscanf(char *fmt,...)
{
    va_list ap;
    char *p;
    int *ival;
    double *dval;
    char *sval;

    va_start(ap,fmt);
    for(p = fmt; *p; p++)
    {
        if(*p != '%')
            continue;
        
        switch(*++p)
        {
            case 'd':
                ival = va_arg(ap,int*);
                scanf("%d",ival);
                break;
            case 'f':
                dval = va_arg(ap,double*);
                scanf("%lf",dval);
                break;
            case 's':
                for(sval = va_arg(ap,char*); *sval; sval++)
                    ;
                scanf("%s",sval);
                break;
            default:
                break;
        }
    }
    va_end(ap);
}
