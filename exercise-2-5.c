#include <stdio.h>
#include <string.h>

#define MAX_STRING_SIZE 100

int any(char s1[], char c);
void findOcurrences(char s1[], char s2[]);

int main()
{
    char s1[MAX_STRING_SIZE] = "example";
    char s2[MAX_STRING_SIZE] = "3rhghgj";

    printf("String 1: %s\n", s1);
    printf("String 2: %s\n", s2);

    findOcurrences(s1, s2);

    return 0;
}

void findOcurrences(char s1[], char s2[])
{
    int i;
    int foundIndex;

    for (i = 0; s2[i] != '\0'; i++)
    {
        foundIndex = any(s1, s2[i]);

        if (foundIndex >= 0)
        {
            break;
        }
    }

    if (foundIndex >= 0)
    {
        printf("First ocurrence found in index %d (indexes starting from 1)\n", foundIndex);
    }
    else
    {
        printf("None of the characters in the second string were found in the first string\n");
    }

}

int any(char s1[], char c)
{
    int i;
    int firstIndex = -1;
    
    for (i = 0; s1[i] != '\0'; i++)
    {
        if (s1[i] == c)
        {
            firstIndex = ++i;

            break;
        }
    }

    return firstIndex;
}