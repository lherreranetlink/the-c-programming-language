#include <stdio.h>

/* count l i n e s i n input */
int main()
{
    int c, nl;
    nl = 0;

    while ((c = getchar ()) != EOF)
        if (c == '\n')
            ++nl;

    printf ("%d\n", nl);
}