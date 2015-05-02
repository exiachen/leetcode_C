#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isPrimes(int n, int *primesList, int index)
{
    int i = 0;
    int limit = (int)sqrt(n);

    if (!primesList)
        return 0;

    for (i = 0; i < index; i++)
    {
        if (primesList[i] > limit)
            break;

        if (n % primesList[i] == 0)
            return 0;
    }

    return 1;
}

int countPrimes(int n)
{
    int i = 0;
    int count = 0;
    int *primes = NULL;
    int index = 0;

    primes = (int *)malloc(n * sizeof(int));
    if (!primes)
    {
        printf("malloc failed\n");
        return 0;
    }

    memset(primes, 0, n * sizeof(int));

    for (i = 2; i < n; i++)
    {
        if (isPrimes(i, primes, index))
        {
            //printf("%d ", i);
            primes[index++] = i;
            count++;
        }
    }
    //printf("\n");

    free(primes);
    return count;
}

int main(int argc, char *argv[])
{
    printf("primes count = %d\n", countPrimes(1000000));
    return 0;
}




