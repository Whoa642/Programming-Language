#include <stdarg.h>

void minprintf(char *fmt, ...)
{
    va_list ap; 
    char *p,*sval;
    char cval;
    int ival;
    double dval;
    void *pval;

    va_start(ap,fmt); 
    for(p = fmt; *p; p++)
    {
        if(*p != '%')
        {
            putchar(*p);
            continue;
        }

        switch(*++p)
        {
            case 'c':
                cval = va_arg(ap,int);
                printf("%c",(char)cval);
                break;
            case 'i':
            case 'd':
                ival = va_arg(ap,int);
                printf("%d",ival);
                break;
            case 'f':
                dval = va_arg(ap,double);
                printf("%f",dval);
                break;
            case 's':
                for(sval = va_arg(ap,char*); *sval; sval++)
                    putchar(*sval);
                break;
            case 'p':
                pval = va_arg(ap,void*);
                printf("%p",pval);
                break;
            default:
                putchar(*p);
                break;
        }
    }
    va_end(ap); 
}
