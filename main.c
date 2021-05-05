#include <stdio.h>
#include <stdlib.h>

double urand()
{
    return (double)rand() / (double)((unsigned)RAND_MAX + 1);
}

int main ()
{
    return 0;
}