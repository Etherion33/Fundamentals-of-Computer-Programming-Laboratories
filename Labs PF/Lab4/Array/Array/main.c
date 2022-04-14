#include <stdio.h>

int main()
{
	int n,m;
	printf("\nEnter how many numbers:");
	scanf_s("%d", &n);
	int tab[201];
	int i;
	for (i = 2; i <= n; i++)
	{
		tab[i] = 1;
	}
	i = 2;
	while (i <= n)
	{
		m = 2 * i;
		while (m <= n)
		{
			tab[m] = 0;
			m += i;
		}
		do {
			i++;
		} while (tab[i] == 0 && i <= n);
	}
	for (i=2; i <= n; i++)
	{
		if (tab[i] == 1) {
			printf("%d \t", i);
		}
	}
	printf("\n");
	system("pause");
	return 0;
}