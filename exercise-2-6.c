#include <stdio.h>
#include <string.h>

unsigned getbits(unsigned x, int p, int n);
unsigned getrightmostbits(unsigned y, int n);

int main()
{
    unsigned x = 3538701066;
    unsigned y = 3538701066;
    unsigned result = 0;
    int n = 5;
    int p = 21;

    int provisional1 = x >> (p + 1); 

    provisional1 = provisional1 << (p + 1);

    int provisional2 = getrightmostbits(x, (p + 1 - n));

    printf("provisional1: %u\n", provisional1);
    printf("provisional1: %u\n", provisional2);

    unsigned provisionalResult1 = provisional1 | provisional2;

    printf("provisionalResult1: %u\n", provisionalResult1);

    unsigned provisional3 = getrightmostbits(y, n);

    printf("provisional3: %u\n", provisional3);

    unsigned provisionalResult2 = provisional3 << (p + 1 - n);

    printf("provisionalResult2: %u\n", provisionalResult2);

    unsigned finalResult = provisionalResult1 | provisionalResult2;

    printf("finalResult: %u\n", finalResult);

}

//get n number of bits starting from position p from an unsigned x leaving the rest of the bits unchanged
unsigned getbits(unsigned x, int p, int n)
{
    return ((x >> (p + 1 - n)) & ~(~0 << n));
}

//get n rightmost bits from unsigned y
unsigned getrightmostbits(unsigned y, int n)
{
    return ~(~0 << n) & y;
} 