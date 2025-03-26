#include <stdio.h>

#define MAXLINE 1000

int getlinecustom(char line[], int maxline);
void reverseString(char line[], char reversed[], int lineSize);
void printline(char line[], int size);

int main()
{
    int lineSize;
    char line[MAXLINE];
    char reversed[MAXLINE];

    while ((lineSize = getlinecustom(line, MAXLINE)) > 0)
    {
        reverseString(line, reversed, lineSize);
        printline(reversed, lineSize);
    }

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

void reverseString(char line[], char reversed[], int lineSize)
{
    int i, j;
    //printf("aqui ando 1");
    for (i = lineSize - 1, j = 0; i >= 0; i--, j++)
        reversed[j] = line[i];
    //printf("Aqui ando 2");
}

void printline(char line[], int size)
{
    int i;
    for (i = 0; i < size; ++i)
        putchar(line[i]);
}