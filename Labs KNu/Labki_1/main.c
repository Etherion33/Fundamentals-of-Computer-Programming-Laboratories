#include <stdio.h>
#include <stdlib.h>

void fill_the_matrix(double ** matrix,int N,int M)
{
    printf("\nFilling Matrix...\n");
    int i,j;
    double s=0.0;
    int direction=0;
       for(i=0;i<N;i++)
        {
            matrix[i]=(double*)malloc(M*sizeof(double));
            for(j= 0;j<M;j++)
            {
                if(direction==0)
                {
                    matrix[i][j]=s;
                    s++;
                    if(j==M-1)
                    {
                        direction=1;
                    }
                }
                if(direction==1)
                {
                    matrix[i*N][j]=s;
                    s++;
                    if(j==M-1)
                    {
                        direction=0;
                    }
                }
            }
        }
}

void show_the_matrix(double ** matrix,int N,int M)
{
    printf("\nPrinting Matrix...\n");
    int i,j;
    for(i=0;i<N;++i)
    {
        for(j=0;j<M;++j)
        {
            printf("%.lf\t",matrix[i][j]);
        }
        printf("\n");
    }
}

void destroy_the_matrix(double **matrix,int N)
{
    int i;
    for(i=0;i<N;i++)
    {
        free(matrix[i]);
    }
    free(matrix);
    matrix=NULL;
    printf("\nFreeing memory...\n");
}


int main()
{
    int N=0,M=0;
    printf("Enter the size of the matrix: (N*M): ");
    scanf("%d",&N);
    scanf("%d",&M);
    printf("\nMatrix size: %d x %d\n",N,M);
    double ** matrix=NULL;
    matrix=(double**)malloc(sizeof(double*)*N);
    fill_the_matrix(matrix,N,M);
    show_the_matrix(matrix,N,M);
    destroy_the_matrix(matrix,N);


    return 0;
}
