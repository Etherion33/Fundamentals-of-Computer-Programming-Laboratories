#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float myIntegral(int *arr, int len)
{
    int i;
    float ft=0;
    for(i=0;i<len;i++)
    {
        ft+=(*(arr+i)*1.0+*(arr+i+1)*1.0)/2;
    }
    return ft;
}

int main()
{
    srand(time(NULL));
    //arr[0]
    //*(arr+0)
    int sizeoftable;
    printf("How long the table should be ?");
    scanf("%d",&sizeoftable);
    int *arr=(int *)malloc(sizeof(int)*sizeoftable);
    int i;
    for(i=0;i<sizeoftable;i++)
    {
        *(arr+i)=rand()%10;
        printf("%d ,",arr[i]);
    }
    //int tab[6]={1,2,2,3,3,4};
    float f=myIntegral(arr,sizeoftable-1);
    printf("\n%f",f);

    //arr[0]=*(arr+3);

    free(arr);
    return 0;
}
