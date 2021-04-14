#include <stdio.h>
#include <ctype.h>
#include <stdlib.h> 
#define MAXVAL 100
#define MAXOP 100 
#define NUMBER '0' 
#define BUFSIZE 100
int getop(char [],char []);
void push(double);
double pop(void);
int sp = 0; 
double val[MAXVAL];

int main(int argc, char *argv[])
{
    char s[MAXOP];
    int type;
    double op2;

    if(argc != 1)
        printf("Usage: expr\n");

    while(--argc > 0)
    {   
        switch(getop(s,*++argv))
        {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop()+pop());
                break;
            case '*':
                push(pop()*pop());
                break;
            case '-':
                op2 = pop();
                push(pop()-op2);
                break;
            case '/':
                op2 = pop();
                if(op2 != 0.0) push(pop()/op2);
                else printf("error: zero divisor\n");
                break;
            case '\n':
                printf("\t%.8g\n",pop());
                break;
            default:
                printf("error: unknown command %s\n",s);
                break;    
        }
    }
    return 0;
}

int getop(char d[],char s[])
{
    int i,c;
    while((c = *d = *s) == ' ' || c == '\t')
        s++;   

    if(!isdigit(c) && c != '.')
        return c;

    if(isdigit(c)) 
        while(isdigit(*++d = c = *s));

    if(c == '.') 
        while(isdigit(*++d = c = *s));
    
    *d = '\0';
    return NUMBER;
}

void push(double f)
{
    if(sp >= MAXVAL)
        printf("error: stack full, can't push %g\n",f);
    else
        val[sp++] = f;
}

double pop(void)
{
    if(sp <= 0)
    {
        printf("error: stack empty\n");
        return 0.0;
    }
    else 
        return val[--sp];
}
