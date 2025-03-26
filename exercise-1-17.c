#include <stdio.h>

#define MAXLINE 1000
#define MIN_LINE_SIZE 80

int getlinecustom(char line[], int maxline);
void printline(char line[], int size);

int main()
{
    int lineSize;
    char line[MAXLINE];

    while ((lineSize = getlinecustom(line, MAXLINE)) > 0)
        if (lineSize >= MIN_LINE_SIZE)
            printline(line, lineSize);

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

void printline(char line[], int size)
{
    int i;
    for (i = 0; i < size; ++i)
        putchar(line[i]);
}