#include <stdio.h>
#include <string.h>

unsigned getbits(unsigned x, int p, int n);
unsigned getrightmostbits(unsigned y, int n);
unsigned setbits(unsigned x, int p, int n, int y);

int main()
{
    unsigned x = 3538701066;
    unsigned y = 3538701066;
    unsigned result = 0;
    int n = 5;
    int p = 21;

    result = setbits(x, p, n, y);

    printf("X: %u\n", x);
    printf("Y: %u\n", y);
    printf("n: %d\n", n);
    printf("p: %d\n", p);
    printf("Result: %u\n", result);

}

//get n number of bits starting from position p from an unsigned x and carries the found bits to the right
unsigned getbits(unsigned x, int p, int n)
{
    return ((x >> (p + 1 - n)) & ~(~0 << n));
}

//get n rightmost bits from unsigned y
unsigned getrightmostbits(unsigned y, int n)
{
    return ~(~0 << n) & y;
} 

//Returns x with the n bits that begin at position p set to the rightmost n bits of y, leaving the other bits unchanged
unsigned setbits(unsigned x, int p, int n, int y)
{
    unsigned provisional1 = 0;
    unsigned provisional2 = 0;
    unsigned provisional3 = 0;
    unsigned provisionalResult1 = 0;
    unsigned provisionalResult2 = 0;
    unsigned finalResult = 0;

    provisional1 = x >> (p + 1); 
    provisional1 = provisional1 << (p + 1);
    provisional2 = getrightmostbits(x, (p + 1 - n));
    provisionalResult1 = provisional1 | provisional2;

    provisional3 = getrightmostbits(y, n);
    provisionalResult2 = provisional3 << (p + 1 - n);

    finalResult = provisionalResult1 | provisionalResult2;

    return finalResult;
}