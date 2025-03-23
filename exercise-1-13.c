#include <stdio.h>

#define IN 0
#define OUT 1
#define MAX_WORD_LENGTH 10
#define MAX_ARRAY_SIZE 11

int main() 
{
    int i, c, j;
    int digits[10];
    int state = OUT;
    int wordLength = 0;

    for (i =0; i < MAX_ARRAY_SIZE; i++)
        digits[i] = 0;

    while ((c = getchar()) != EOF)
    {
        if (state == IN)
        {
            if (c == ' ' || c == '\n' || c == '\t')
            {
                state = OUT;
                
                if(wordLength <= MAX_WORD_LENGTH) 
                    digits[wordLength]++;
                
                wordLength = 0;
            }
            else
                wordLength++;
        }
        else 
        {
            if (c != ' ' && c != '\n' && c != '\t')
            {
                state = IN;
                wordLength++;
            }
        }
    }

    for (i =1; i < MAX_ARRAY_SIZE; i++)
    {
        printf(" %d:", i);
            for(j = 0; j < digits[i]; j++)
                printf("-");
        printf("\n");
    }
}