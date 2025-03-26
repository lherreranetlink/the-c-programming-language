#include <stdio.h>

#define MAXLINE 1000

int getWholeInput(char line[], int maxline);
int removeBlanks(char oldLine[], char newLine[], int lim);
void printline(char line[], int size);

int main()
{
    int lineSize;
    char line[MAXLINE];
    char newLine[MAXLINE];

    while ((lineSize = getWholeInput(line, MAXLINE)) > 0)
    {
        int newSize = removeBlanks(line, newLine, lineSize);
        printline(newLine, newSize);
    }

    return 0;
}

int getWholeInput(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF; ++i)
        s[i] = c;
    
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';

    return i;
}

int removeBlanks(char oldLine[], char newLine[], int lim)
{

    int i, j, c;

    for (i = 0, j = 0; i < lim; ++i)
    {
        c = oldLine[i];
        if (c != ' ' && c != '\t' && c != '\n')
        {
            newLine[j] = c;
            j++;
        }
    }

    newLine[j] = '\0';

    return j;
}

void printline(char line[], int size)
{
    int i;
    for (i = 0; i < size; ++i)
        putchar(line[i]);
}