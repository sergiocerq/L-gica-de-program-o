#include <stdio.h>
#include <stdlib.h>
int main () {
    float somanumeros (float num1, float num2);

    float a, b, soma;
    printf("Informe o valor A: ");
    scanf("%f", &a);
    printf("Informe o valor b: ");
    scanf("%f", &b);
    soma = somanumeros (a, b);
    printf("%.2f", soma);
    return 0;
}
float somanumeros (float num1, float num2) {
     float transformavalores(float x);
    if(a < 0) {
        num1 =  transformavalores(num1);
    }
    if(b < 0) {
        num2 =  transformavalores(num2);
    }
    return num1 + num2;
}
float tranformavalores(float x) {
    return x *-1;
}