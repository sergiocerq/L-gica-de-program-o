//fibonacci
#include <stdio.h>
#include <stdlib.h>
int main() {
	int i=0, z=0, x=0, y=1;
	for(i=1;i<=10;i++) {
		z=x+y;
		printf("%d ",z);
		x=z;
		z=x+y;
		printf("%d ",z);
		y=z;
	}
	return 0;
}
