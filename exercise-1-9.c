#include <stdio.h>

int main()
{
    int c = 0;
    int blankCounter = 0;

    while((c = getchar()) != EOF)
    {
        if(c == ' ' || c == '\t')
        {
            if(blankCounter < 1)
                putchar(c);
            blankCounter++;
        } 
        else 
        {
            putchar(c);
            blankCounter = 0;
        }
            
    }
}