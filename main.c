#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double urand ()
{
    int r;
    r = rand ();
    return (double) r / RAND_MAX;
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

    printf ("Numarul de succese din cele %g incercari: %g\n", n, k);
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

    printf ("Numarul de incercari pana la primul succes (inclusiv): %g\n", k);
}

void FunGeom2 (double p)
{
    double u;
    int k;

    u = urand ();
    k = (int) (log (1 - u) / log (1 - p)) + 1;

    printf ("Numarul de incercari pana la primul succes (inclusiv): %g\n", k);
}

void FunPoiss (double lambda)
{
    int n = 0;
    double u, limit;

    limit = exp (-lambda);
    u = urand ();

    while (u > limit)
    {
        n++;
        u *= urand ();
    }

    printf ("Numarul de evenimente rare ce au avut loc in unitatea de timp: %d\n", n);
}

void FunUnifDiscr (int m, int n)
{
    double u;
    int k;

    u = urand();

    k = (int)((n - m + 1) * u);
    k = k + m;

    printf("Valoare %d a fost simulata din multimea selectata\n", k);
}

void FunNeunifDiscr (double *x, double *p)
{
    int k = 0;
    double F = p[0];
    double u;

    u = urand();
    while (u > F)
    {
        k = k + 1;
        F = F + p[k];
    }

    printf("Valoare %g a fost simulata\n", x[k]);
}


int main ()
{
    srand(time(NULL));
    int optiune, nr, a, b, aux, val;
    double p, n, x[100], prob[100], lambda;

    printf("\nSimularea variabilelor aleatoare.\n\n");

    do
    {
        printf("1 - Simularea distributiei Bernoulli\n");
        printf("2 - Simularea distributiei Binomiale\n");
        printf("3 - Simularea distributiei Geometrica\n");
        printf("4 - Simularea distributiei Poisson\n");
        printf("5 - Simularea distributiei uniforme discrete\n");
        printf("6 - Simularea distributiei neuniforme discrete\n");
        printf("7 - Iesire\n");

        printf("\n");

        printf ("Introduceti optiunea: "); scanf ("%d", &optiune);
        if (optiune != 7)
        {
            printf("De cate ori sa fie simulata? ");
            scanf("%d", &nr);
        }
        printf("\n");
        
        switch (optiune)
        {
            case 1:
                printf("Probabilitatea succesului: "); scanf("%lf", &p);
                printf("\n");

                for (int i = 0; i < nr; ++i)
                    FunBern(p);
                
                printf("\n");
                
                printf("Media este: %g\n", p);
                printf("Dispersia este: %g\n", p * (1 - p));

                printf("\n");
                break;

            case 2:
                printf ("Numarul de incercari: "); scanf ("%lf", &n);
                printf ("Probabilitatea succesului: "); scanf ("%lf", &p);

                printf("\n");

                for (int i = 0; i < nr; ++i)
                    FunBin (n, p);

                printf("\n");

                printf("Media este: %g\n", n * p);
                printf("Dispersia este: %g\n", n * p * (1 - p));

                printf("\n");
                break;

            case 3:
                printf ("Probabilitatea succesului: "); scanf ("%lf", &p);

                printf("\n");

                for (int i = 0; i < nr; ++i)
                    FunGeom1 (p);

                printf("\n");

                printf("Media este: %g\n", 1 / p);
                printf("Dispersia este: %g\n", (1 - p) / (p * p));

                printf("\n");
                break;

            case 4:
                printf ("Rata de aparitie a eventului rar in unitatea de timp (fixata): "); scanf("%lf", &lambda);

                printf("\n");

                for (int i = 0; i < nr; ++i)
                    FunPoiss(lambda);

                printf("\n");

                printf("Media si disperia sunt: %g\n", lambda);

                printf("\n");

                break;

            case 5:
                printf("Primul si ultimul element al multimii (numere intregi): "); scanf("%d %d", &a, &b);
                if (a > b)
                {
                    aux = a;
                    a = b;
                    b = aux;
                }

                printf("\n");

                printf("Se simuleaza %d valori din multimea { ", nr);
                for (int i = a; i <= b; ++i)
                    printf("%d ", i);
                printf("}\n"); 

                printf("\n");

                for (int i = 0; i < nr; ++i)
                    FunUnifDiscr(a, b);

                printf("\n");
                break;

            case 6:
                printf("Cititi numarul de valori (maxim 100): "); scanf("%d", &val);

                printf("\n");
                
                printf("Cititi valorile (in ordine crescatoare) si probabilitatile lor (suma lor = 1): \n");
                for (int i = 0; i < val; ++i)
                {
                    printf("Valorea: "); scanf("%lf", &x[i]);
                    printf("Probabilitatea: "); scanf("%lf", &prob[i]);
                    printf("\n");
                }

                printf("\n");

                for (int i = 0; i < nr; ++i)
                    FunNeunifDiscr(x, prob);

                printf("\n");

                break;

            case 7:
                printf("\n");
                break;
        
            default:
                printf("Optiune invalida!\n");
                break;
        }

    } while (optiune != 7);


    return 0;
}