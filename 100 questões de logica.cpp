//numeros triangulares
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i, n, a;
	printf("Informe um numero:\n");
	scanf("%d", &a);
	
	for(n=1; (n+2) <= a; ++n)
	{
		
	i = n * (n+1) * (n+2);
	if(i==a)
	break;	
	}

	if(i==a)
	printf("O numero e triangular.\n");
	else
	printf("O numero nao e triangular.\n");	
	
	
	return 0;
}