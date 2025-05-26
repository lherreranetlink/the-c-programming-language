#include <stdio.h>
#include <string.h>

#define MAX_INPUT_SIZE 102 //100 Characteres and 2 extra considering 0x
#define NULL_CHARACTER '\0'

int htoi(char s[]);

int main()
{
    char input[MAX_INPUT_SIZE + 1]; //An extra charcater for null character
    int c, count = 0;
    int converted = 0;

    while (((c = getchar()) != EOF && c != '\n') || count >= MAX_INPUT_SIZE) 
    {
        input[count] = c;
        count++;
    }

    if (count >= MAX_INPUT_SIZE)
        printf("Warning, input size provided exceeds the maximum lenght permited, input will be turncated to %d\n", MAX_INPUT_SIZE);

    input[count] = NULL_CHARACTER;

    converted = htoi(input);

    if (converted >= 0)
        printf("%d\n", htoi(input));
    else
        printf("Error: Illegal hexadecimal digits: %s\n", input);

}

int htoi(char s[])
{
    int rt = 0;
    int start = 0;

    if (strlen(s) > 2)
    {
        char first = s[0];
        char second = s[1];

        if (first == '0' && (second == 'x' || second == 'X'))
        {
            start = 2;
        }
    }

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