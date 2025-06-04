#include <stdio.h>
#include <string.h>

unsigned getbits(unsigned x, int p, int n);
unsigned getrightmostbits(unsigned y, int n);

int main()
{

    unsigned number = 1000;
    int n = 5;
    int y = 8;
    unsigned nbitsfromp = getbits(number, 9, n);
    unsigned righmostnfromy = getrightmostbits(y, n);

    unsigned result = number & ((righmostnfromy << n) | ~(~0 << n)); 

    printf("Resultado locochon: %u\n", result);

    //printf("Resultado locochon: %u\n", test2);

    return 0;
}

//get n number of bits starting from position p from an unsigned x leaving the rest of the bits unchanged
unsigned getbits(unsigned x, int p, int n)
{
    return ((x >> (p + 1 - n)) & ~(~0 << n)) << (p + 1 - n);
}

//get n rightmost bits from unsigned y
unsigned getrightmostbits(unsigned y, int n)
{
    return ~(~0 << n) & y;
} 