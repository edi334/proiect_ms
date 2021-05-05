#include <stdio.h>
#include <stdlib.h>

double urand()
{
    return (double) rand() / (double) ((unsigned) RAND_MAX + 1);
}

void FunBin (double n, double p)
{
    double k = 0;
    double c = (double) p / (double) (1 - p);
    double pr = (double) pow ((1 - p), n);
    double S = pr;

    double u = urand();

    while (u > S)
    {
        pr = ((double) (c * (n - k)) / (double) (k + 1)) * pr;
        S += pr;
        k++;
    }

    printf ("Numărul de succese din cele %ld încercări: %ld\n", n, k);
}

int main ()
{
    return 0;
}