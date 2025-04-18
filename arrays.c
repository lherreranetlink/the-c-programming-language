#include <stdio.h>

int main()
{
    int c, i, nWhite, nOther;
    int nDigits[10];

    nWhite = nOther = 0;

    for (i =0; i < 10; i++)
        nDigits[i] = 0;
        
    while ((c = getchar()) != EOF)
        if (c >= '0' && c <= '9')
            ++nDigits[c - '0'];
        else if (c == ' ' || c == '\n' || c == '\t')
            ++nWhite;
        else
            ++nOther;
    
    printf("digits = ");

    for (i =0; i < 10; i++)
        printf(" %d", nDigits[i]);

    printf(", white spaces = %d, other = %d", nWhite, nOther);
}