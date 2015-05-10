#include <stdio.h>
#include <stdlib.h>

static int bitWidth(int num)
{
    int width = 0;

    while (num)
    {
        width++;
        num >>= 1;
    }

    return width;
}

int rangeBitwiseAnd(int m, int n) {
    int diff = n - m;

    return (n & m) & ((-1) << bitWidth(diff));
}

int main(int argc, char const *argv[])
{
    printf("result = %d\n", rangeBitwiseAnd(6, 7));
    return 0;
}