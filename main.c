#include <stdio.h>
#include <stdlib.h>

double urand()
{
    return (double)rand() / (double)((unsigned)RAND_MAX + 1);
}

void FunBern (double p)
{
    double u = urand();
    if (u < p)
        printf("Evenimentul s-a produs\n");
    else
        printf("Evenimentul nu s-a produs\n");
}

int main ()
{
    int optiune, nr;
    double p;

    printf("Simularea variabilelor aleatoare.\n");

    do
    {
        printf("1 - Simularea distribuției Bernoulli\n");
        printf("2 - Simularea distribuției Binomiale\n");
        printf("3 - Simularea distribuției Geometrică\n");

        switch (optiune)
        {
            printf("De cate ori sa fie simulată?\n");
            scanf("%d", &nr);
            case 1:
                printf("Probabilitatea succesului: ");
                scanf("%ld", &p);
                for (int i = 0; i < nr; ++i)
                    FunBern(p);
                printf("Media este %ld\n", p);
                printf("Dispersia este %ld", p * (1 - p));
                break;
            case 4:
                break;
        
            default:
                printf("Opțiune invalidă!\n");
                break;
        }
    }while (optiune != 4);


    return 0;
}