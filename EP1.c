#include <stdio.h>
#include <math.h>
#include <complex.h>

const double EPS = 1e-8;

// g(x) = x <-> f(x) = 0
double ABS(double x){
    if(x > -EPS) return x;
    return -x;
}

double metodo_ponto_fixo(double x0, double (*f)(double), double (*G)(double)){
    double raiz = x0;
    int limite_iteracoes = 100;
    while((ABS(f(raiz)) > EPS || ABS(raiz - G(raiz)) > EPS) && limite_iteracoes > 0){
        // printf("%f\n", raiz);
        limite_iteracoes--;
        raiz = G(raiz);
    }
    if(limite_iteracoes == 0) return NAN;
    return raiz;
}

double f(double x){
    return exp(x) - 2 * x * x;
}

// raiz = 1
double g(double x){
    return f(x) + x;
}

// raiz = 2, 1
double g1(double x){
    return -f(x) / 2 + x;
}

int main(){
    double raiz = 1;
    raiz = metodo_ponto_fixo(raiz, f, g);
    printf("A primeira raiz é: %.8f\n", metodo_ponto_fixo(1, f, g));
    printf("A segunda raiz é: %.8f\n", metodo_ponto_fixo(2, f, g1));
    printf("A terceira raiz é: %.8f\n", metodo_ponto_fixo(1, f, g1));
}