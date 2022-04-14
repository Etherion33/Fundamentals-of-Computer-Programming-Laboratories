#include <stdio.h>
#include <math.h>

int main()
{
	/*int number;
	scanf_s("%d", &number);
	long long int n = 99999999;
	int prime = 1;

	for (int i = 2; i*i <= n; i++)
	{
		if(number%i==0)
			{
				printf("\nIt isn't prime number!, div=%d\n",i);
				prime = 0;
			}
	}
	if (prime == 1)
	{
		printf("\nIt is prime number!\n");
	}
	system("pause");

	return 0;*/


	double x;
	double prev_x;
	prev_x = 2000.0;
	x = 1000.0;
	while(x!=prev_x)
	{
		prev_x = x;
		x = (x + 1000.0/ x) / 2.0;
		printf("Result: %f \n", x);
	}
	system("pause");
}