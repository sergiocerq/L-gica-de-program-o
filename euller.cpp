//euller
#include <stdio.h>
#include <stdlib.h>
int main()
{
	float i, n, e, j, k;
	printf("Informe um valor n.\n");
	scanf("%f",&n);
	
	for(i=1, e=1;i<=n;i++)
	{
		for(k=i, j=1;k>=1;k--)
		{
			j*=k;
		}
		j=1/j;
		e+=j;
	}
	printf("Valor de e= %3f", e);
	return 0;
}
