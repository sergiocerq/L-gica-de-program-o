//Sequência de recamán
#include <stdio.h>
#include <stdlib.h>
int main () {
 
    int i, j=0, an, am=0, resposta[20];

    for(i=0;i<20;i++) {
        an = am;
        am = an - i;
        if(am > 0) {
         for(j=0;j<=i;j++) {
         if(am == resposta[j])
         am = an + i;
         continue;
        }
        resposta[i] = am;
        continue;
        }
        else {
        am = an + i;
        resposta[i] = am;
        }
       
    }
    for(i=0; i<20; i++)
     printf("Sequencia: %d\n", resposta[i]);
    
    
    return 0;
}