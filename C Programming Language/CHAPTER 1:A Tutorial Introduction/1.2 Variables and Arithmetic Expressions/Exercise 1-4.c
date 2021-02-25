#include <stdio.h>

int main()
{
    float fahr, celsius;
    int lower,upper,step;

    lower = 0;
    upper = 300;
    step = 20;

    celsius = lower;
    printf("The program prints the table of temperatures in Celsius and Fahrenheit.\n");
    while(celsius <= upper)
    {
        fahr = (9.0/5.0)*celsius+32;
        printf("%3.0f %6.1f\n",celsius,fahr);
        celsius += step;
    }

    return 0;
}
