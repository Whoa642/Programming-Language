#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h> 
#define MAXVAL 100 
#define MAXOP 100 
#define NUMBER '0'
#define BUFSIZE 100 
int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

int sp = 0; 
double val[MAXVAL]; 
char buf[BUFSIZE]; 
int bufp = 0;

int main()
{
    int type;
    double op1,op2;
    char s[MAXOP];

    while((type = getop(s)) != EOF)
    {
        switch(type)
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
            case '%':
                op2 = pop();
                if(op2 != 0.0) push(fmod(pop(),op2));
                else printf("error: zero divisor\n");
                break;
            case '\n':
                printf("\t%.8g\n",pop());
                break;
            case 't':
                op1 = pop();
                printf("\t%.8g\n",op1);
                push(op1);
                break;
            case 'd':
                op1 = pop();
                push(op1);
                push(op1);
                break;
            case 's':
                op1 = pop();
                op2 = pop();
                push(op1);
                push(op2);
                break;
            case 'c':
                sp = 0;
                break;
            default:
                printf("error: unknown command %s\n",s);
                break;
        }
    }
}

void push(double f) 
{
    if(sp < MAXVAL) val[sp++] = f;
    else printf("error: stack full, can't push %g\n",f);

}

double pop(void) 
{
    if(sp > 0) return val[--sp];
    else 
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}

int getop(char s[]) 
{
    int i,c;

    while((s[0] = c = getch()) == ' ' || c == '\t');
    s[1] = '\0'; 
    i = 0;

    if(!isdigit(c) && c != '.') return c;

    if(isdigit(c)) 
        while(isdigit(s[++i] = c = getch()));

    if(c == '.') 
        while(isdigit(s[++i] = c = getch()));
    
    s[i] = '\0';
    if(c != EOF) ungetch(c);
    return NUMBER;
}

int getch(void) 
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if(bufp >= BUFSIZE) printf("ungetch: too many characters\n");
    else buf[bufp++] = c;
}
