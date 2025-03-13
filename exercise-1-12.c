#include <stdio.h>

#define IN 0
#define OUT 1

int main() 
{
    int c;
    int state = OUT;

    while ((c = getchar()) != EOF)
    {
        if (state == IN)
        {
            if (c == ' ' || c == '\n' || c == '\t')
            {
                putchar('\n');
                state = OUT;
            }
            else 
            {
                putchar(c);
            }
        }
        else 
        {
            if (c != ' ' && c != '\n' && c != '\t')
            {
                state = IN;
                putchar(c);
            }
        }
    }
}