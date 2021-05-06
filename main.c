#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double urand ()
{
    return (double)rand() / (double)RAND_MAX ;
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

    printf ("Numarul de succese din cele %ld incercari: %ld\n", n, k);
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

    printf ("Numarul de incercari pana la primul succes (inclusiv): %ld\n", k);
}

void FunGeom2 (double p)
{
    double u;
    int k;

    u = urand ();
    k = (int) (log (1 - u) / log (1 - p)) + 1;

    printf ("Numarul de incercari pana la primul succes (inclusiv): %ld\n", k);
}

void FunUnifDiscr (int m, int n)
{
    double u;
    int k;

    u = urand();
    printf("%ld\n", u);
    k - (int)((n - m + 1) * u);
    k = k + m;

    printf("Valoare %d a fost simulata din multimea selectata\n");
}



int main ()
{
    int optiune, nr, a, b, aux;;
    double p, n;

    printf("Simularea variabilelor aleatoare.\n");

    do
    {
        printf("1 - Simularea distributiei Bernoulli\n");
        printf("2 - Simularea distributiei Binomiale\n");
        printf("3 - Simularea distributiei Geometrica\n");
        printf("4 - Simularea distrbutiei uniforme discrete\n");

        printf ("Introduceti optiunea: \n"); scanf ("%d", &optiune);
        printf("De cate ori sa fie simulata?\n"); scanf("%d", &nr);

        switch (optiune)
        {
            case 1:
                printf("Probabilitatea succesului: "); scanf("%ld", &p);

                for (int i = 0; i < nr; ++i)
                    FunBern(p);
                
                printf("Media este: %ld\n", p);
                printf("Dispersia este: %ld", p * (1 - p));
                break;

            case 2:
                printf ("Numarul de incercari: "); scanf ("%ld", &n);
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
                printf("Primul si ultimul element al multimii (numere intregi): "); scanf("%d %d", &a, &b);
                if (a > b)
                {
                    aux = a;
                    a = b;
                    b = aux;
                }
                printf("Se simuleaza %d valori din multimea { ", nr);
                for (int i = a; i <= b; ++i)
                    printf("%d ", i);
                printf("}\n"); 
                for (int i = 0; i < nr; ++i)
                    FunUnifDiscr(a, b);

            case 5:
                break;
        
            default:
                printf("Optiune invalida!\n");
                break;
        }

    } while (optiune != 5);


    return 0;
}