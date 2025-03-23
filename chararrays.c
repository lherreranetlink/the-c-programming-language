#include <stdio.h>

#define MAXLINE 1000

int getlinecustom(char line[], int maxline);
void copycustom(char from[], char to[]);

int main()
{
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while ((len = getlinecustom(line, MAXLINE)) > 0)
        if (len > max)
        {
            max = len;
            copycustom(line, longest);
        }

    if (max > 0)
        printf("%s", longest);

    return 0;
}

int getlinecustom(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';

    return i;
}

void copycustom(char from[], char to[])
{
    int i;

    i = 0;
    while((to[i] = from[i]) != '\0')
        ++i;
}