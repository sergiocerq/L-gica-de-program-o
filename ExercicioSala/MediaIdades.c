#include <stdio.h>
int main () {

int n, i, total;  //declaração de variaveis
float media=0.0;

printf("informe o numero de idades:\n");  //leitura da quantidade n de idades
scanf("%d", &n);

int idades[n]; //criação do vetor para salvar a quantidade de idades

for(i=0;i<n;i++) {   //procedimento para salvar os dados no vetor
printf("Informe a %d idade: ", i+1);
scanf("%d", &idades[i]);
media += idades[i];
}
media/=n;  //calculo da media
printf("Media: %.2f\n", media);

for(i=0;i<n;i++){  //procedimento para ver se a idade e maior que a media
if(idades[i] > media)
printf("Idade: %d\n", idades[i]);
}
return 0;
}