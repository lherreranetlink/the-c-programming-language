#include <stdio.h>

#define STRING_SIZE 100
#define END_OF_STRING '\0'

void escape(char s[], char t[]); 
void unescape(char t[], char s[]);


int main()
{
    char s[STRING_SIZE] = "sdfsdfdsf\t\t\tkjhjkhj\t\tjhjjhjjhj\nsdfsdfdsfdsf";
    char t[STRING_SIZE];

    printf("Original String s: %s\n", s);

    escape(s, t);

    printf("String t (s escaped): %s\n", t);

    unescape(t, s);

    printf("String s unescaped: %s\n", s);

    return 0;
}


void escape(char s[], char t[]) 
{
    char c;
    int i = 0;
    int j = 0;

    while ((c = s[i]) != END_OF_STRING) 
    {
        switch (c) 
        {
            case '\t':
                t[j] = '\\';
                j++;
                t[j] = 't';
            break;
            case '\n':
                t[j] = '\\';
                j++;
                t[j] = 'n';
            break;
            default:
                t[j] = c; 
        }
        i++;
        j++;
    }
    t[j] = END_OF_STRING;
}

void unescape(char t[], char s[])
{
    char c;
    int i = 0;
    int j = 0;

    while ((c = t[i]) != END_OF_STRING)
    {
        switch(c)
        {
            case '\\':
                if (t[i + 1] != END_OF_STRING) 
                {
                    i++;
                    if (t[i] == 't') 
                    {
                        s[j] = '\t';
                    }
                    else if (t[i] == 'n')
                    {
                        s[j] = '\n';
                    }
                }
                else
                {
                    s[j] = c; 
                }
            break;
            default:
                s[j] = c; 
        }
        i++;
        j++;
    }

    s[j] = END_OF_STRING;
}