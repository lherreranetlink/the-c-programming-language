#include <stdio.h>

int main ()
{
    int lineSize;
    const char line[] = "const example";
    const int number = 5;

    printf("const string %s\n", line);
    printf("const int %d\n", number);
    
    return 0;
}