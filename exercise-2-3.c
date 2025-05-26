#include <stdio.h>
#include <string.h>

#define MAX_INPUT_SIZE 6
#define NULL_CHARACTER '\0'

int htoi(char s[]);

int main()
{
    char input[MAX_INPUT_SIZE + 1]; //An extra charcater for null character
    int c;
    int stringSize = 0;
    int converted = 0;
    int iterations = 0;

    while (((c = getchar()) != EOF && c != '\n') && stringSize < MAX_INPUT_SIZE) 
    {
        if (!((c == '0' || c == 'x' || c == 'X') && stringSize == 0) || iterations >= 2)
        {
            input[stringSize] = c;
            stringSize++;
        }
        iterations++;
    }

    input[stringSize] = NULL_CHARACTER;

    converted = htoi(input);

    if (converted >= 0)
        printf("Decimal value: %d\n", htoi(input));
    else
        printf("Error: Illegal hexadecimal digits: %s\n", input);

    return 0;

}

int htoi(char s[])
{
    int rt = 0;
    int start = 0;

    int i;
    char c;
    for (i = start; (c = s[i]) != '\0'; i++)
    {
        int v;
        if ('0' <= c && c <= '9')
            v = c - '0';
        else if ('a' <= c && c <= 'f')
            v = 10 + c - 'a';
        else if ('A' <= c && c <= 'F')
            v = 10 + c - 'A';
        else
            return -1;
        
        rt = rt * 16 + v;
    }
    return rt;
}