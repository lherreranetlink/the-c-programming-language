#include <stdio.h>
#include <string.h>

#define MAX_STRING_SIZE 100

void squeezeStrings(char s1[], char s2[]);
void squeezeChar(char s1[], char c);

int main()
{
    char s1[MAX_STRING_SIZE] = "example";
    char s2[MAX_STRING_SIZE] = "qwdeedas";

    printf("String 1: %s\n", s1);
    printf("String 2: %s\n", s2);

    squeezeStrings(s1, s2);

    printf("Resulting string: %s\n", s1);

    return 0;
}

void squeezeStrings(char s1[], char s2[])
{
    int i;

    for (i = 0; s2[i] != '\0'; i++)
        squeezeChar(s1, s2[i]);
}

void squeezeChar(char s1[], char c)
{
    int i, j;

    for (i = j = 0; s1[i] != '\0'; i++)
        if (s1[i] != c)
            s1[j++] = s1[i];

    s1[j] = '\0';
}