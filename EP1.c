#include <stdio.h>
#include <math.h>
#include <complex.h>

const double EPS = 1e-8;

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

double ABS(double x){
    if(x > -EPS) return x;
    return -x;
}

int main(){
    double raiz = 1;
    while(ABS(f(raiz)) > EPS || ABS(raiz - g(raiz)) > EPS){
        // printf("%f\n", raiz);
        raiz = g(raiz);
    }
    printf("%.8f   %.8f", raiz, f(raiz));
}
