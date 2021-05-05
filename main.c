#include <stdio.h>
#include <stdlib.h>



double urand ()
{
    return (double) rand() / (double) ((unsigned) RAND_MAX + 1);
}


void FunBin (double n, double p)
{
    double k = 0;
    double c = (double) p / (double) (1 - p);
    double pr = (double) pow ((1 - p), n);
    double S = pr;

    double u = urand ();

    while (u > S)
    {
        pr = ((double) (c * (n - k)) / (double) (k + 1)) * pr;
        S += pr;
        k++;
    }

    printf ("Numărul de succese din cele %ld încercări: %ld\n", n, k);
}

void FunBern (double p)
{
    double u = urand();
    if (u < p)
        printf("Evenimentul s-a produs\n");
    else
        printf("Evenimentul nu s-a produs\n");
}

void FunGeom1 (double p)
{
    double k = 0;
    double u;

    do {

        u = urand ();
        k++;

    } while (u > p);

    printf ("Numărul de încercări până la primul succes (inclusiv): %ld\n", k);
}

void FunGeom2 (double p)
{
    double u;
    int k;

    u = urand ();
    k = (int) (log (1 - u) / log (1 - p)) + 1;

    printf ("Numărul de încercări până la primul succes (inclusiv): %ld\n", k);
}



int main ()
{
    int optiune, nr;
    double p, n;

    printf("Simularea variabilelor aleatoare.\n");

    do
    {
        printf("1 - Simularea distribuției Bernoulli\n");
        printf("2 - Simularea distribuției Binomiale\n");
        printf("3 - Simularea distribuției Geometrică\n");

        printf ("Introduceți opțiunea: \n"); scanf ("%d", &optiune);

        switch (optiune)
        {
            printf("De cate ori sa fie simulată?\n"); scanf("%d", &nr);

            case 1:
                printf("Probabilitatea succesului: "); scanf("%ld", &p);

                for (int i = 0; i < nr; ++i)
                    FunBern(p);
                
                printf("Media este: %ld\n", p);
                printf("Dispersia este: %ld", p * (1 - p));
                break;

            case 2:
                printf ("Numărul de încercări: "); scanf ("%ld", &n);
                printf ("Probabilitatea succesului: "); scanf ("%ld", &p);

                for (int i = 0; i < nr; ++i)
                    FunBin (n, p);

                printf("Media este: %ld\n", n * p);
                printf("Dispersia este: %ld", n * p * (1 - p));
                break;

            case 3:
                printf ("Probabilitatea succesului: "); scanf ("%ld", &p);

                for (int i = 0; i < nr; ++i)
                    FunGeom1 (p);            // am lasat geom1 deocamdata

                printf("Media este: %ld\n", 1 / p);
                printf("Dispersia este: %ld", (1 - p) / (p * p));
                break;



            case 4:
                break;
        
            default:
                printf("Opțiune invalidă!\n");
                break;
        }

    } while (optiune != 4);


    return 0;
}