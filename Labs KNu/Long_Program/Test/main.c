#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    FILE *plik;
    plik  = fopen("test.txt","r");
    double *p1[3];
    char p2[10]="test";
    //double wynik=2.0-2.0*M_E^2.0;
    printf("\nRozmiar p1: %d",sizeof(p1));
    printf("\nRozmiar p2: %d",sizeof(p2));
    //printf("\n2-2e2: %lf",wynik);
    mycopy(plik);
    return 0;
}

void mycopy(FILE *plik)
{
    char c;
    while((c=getc(plik))!=EOF)
    {
        printf("%c",c);
    }
}
