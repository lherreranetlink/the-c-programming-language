#include <stdio.h>

#define MAX_LENGTH 1000
#define LINE_NUM 100
#define TAB_WIDTH 4

int readLine(char line[], int maxLength);
void copy(char from[], char to[]);
void detab(char line[], char result[]);

int main() 
{
    printf("Input: \n");

    char lines[LINE_NUM][MAX_LENGTH];
    char line[MAX_LENGTH];
    char result[MAX_LENGTH];
    int lineId = 0, length = 0;

    while ((length = readLine(line, MAX_LENGTH)) != 0) 
    {
        detab(line, result);
        copy(result, lines[lineId]);
        lineId++;
    }
    
    printf("\n\nOutput: \n");

    for (int i = 0; i <= lineId; i++)
        printf("%s\n", lines[i]);

    return 0;
}

int readLine(char line[], int maxLength) 
{
    char ch;
    int length = 0;

    while ((ch = getchar()) != EOF && ch != '\n' && length < maxLength) 
    {
        line[length] = ch;
        length++;
    }

    if (ch == '\n') 
        line[length] = '\0';

    return length;
}

void copy(char from[], char to[]) 
{
    int i = 0;

    while (from[i] != '\0') 
    {
        to[i] = from[i];
        i++;
    }

    to[i] = '\0';
}

void detab(char line[], char result[]) 
{
    int i = 0;
    char ch;
    int column = 0;
    int spaces;
    int nextTabStop;

    while ((ch = line[i++]) != '\0') 
    {
        if (ch == '\t') 
        {
            spaces = TAB_WIDTH - column % TAB_WIDTH;
            nextTabStop = column + spaces;

            for (; column < nextTabStop; column++)
                result[column] = ' ';

        } 
        else 
        {
            result[column] = ch;
            column++;
        }
    }
    
    result[column] = '\0';
}