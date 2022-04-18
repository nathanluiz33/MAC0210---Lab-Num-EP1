#include <stdio.h>
#include <math.h>

const double EPS = 1e-8;

/* ABS: retorna o valor absoluto de um real x
*/
double ABS(double x){
    if(x > -EPS) return x;
    return -x;
}

/* metodo_ponto_fixo: função que retorna um double sendo a raiz para onde
*  um ponto converge pelo Método do Ponto Fixo. Caso não haja convergência, retorna NAN.
*  x0 -> ponto inicial de iteracao, f -> função em que vamos utilizar o método
*  df -> derivada de f, lim_iteracoes -> número máximo permitido de iteracoes do método
*  para utilizar esse método, é necessária a condição de g(x) = x <-> f(x) = 0
*/
double metodo_ponto_fixo(double x0, double (*F)(double), double (*G)(double), int limite_iteracoes){
    double raiz = x0;
    while((ABS(F(raiz)) > EPS || ABS(raiz - G(raiz)) > EPS) && limite_iteracoes > 0){
        limite_iteracoes--;
        raiz = G(raiz);
    }
    if(limite_iteracoes == 0) return NAN;
    return raiz;
}

// função eˆx - 2 xˆ2
double f(double x){
    return exp(x) - 2 * x * x;
}

// essa função converge para r_1 se o ponto inicial for 1
double g(double x){
    return f(x) + x;
}

// essa função converge para r_0 se o ponto inicial for 1 e para r_2 se o ponto inicial for 2
double g1(double x){
    return -f(x) / 2 + x;
}

int main(){
    double r0 = metodo_ponto_fixo(1, f, g1, 40), r1 = metodo_ponto_fixo(1, f, g, 40), r2 = metodo_ponto_fixo(2, f, g1, 40);
    printf("A primeira raiz é: %.8f\n", r0);
    printf("A segunda raiz é: %.8f\n", r1);
    printf("A terceira raiz é: %.8f\n\n", r2);

    // as buscas binárias abaixo são para achar o menor e maior valor que converge para cada raiz
    // nas funções g e g1
    double ini = -1, fim = 0;
    while(fim - ini > EPS){
        double meio = (ini + fim) / 2;
        if(metodo_ponto_fixo(meio, f, g, 40) < 2) fim = meio;
        else ini = meio;
    }
    printf("Menor valor que converge para r1 em g(x): %.8f\n", ini);

    ini = 0, fim = 3;
    while(fim - ini > EPS){
        double meio = (ini + fim) / 2;
        if(metodo_ponto_fixo(meio, f, g, 40) < 2) ini = meio;
        else fim = meio;
    }
    printf("Maior valor que converge para r1 em g(x): %.8f\n\n", ini);

    ini = -3, fim = 0;
    while(fim - ini > EPS){
        double meio = (ini + fim) / 2;
        if(metodo_ponto_fixo(meio, f, g1, 40) < 2) fim = meio;
        else ini = meio;
    }
    printf("Menor valor que converge para r0 em g1(x): %.8f\n", ini);

    ini = 0, fim = 2;
    while(fim - ini > EPS){
        double meio = (ini + fim) / 2;
        if((metodo_ponto_fixo(meio, f, g1, 40) - r0) < EPS) ini = meio;
        else fim = meio;
    }
    printf("Maior valor que converge para r0 em g1(x): %.8f\n\n", ini);


    printf("Menor valor que converge para r2 em g1(x): %.8f\n", ini);
    ini = 2, fim = 5;
    while(fim - ini > EPS){
        double meio = (ini + fim) / 2;
        if((metodo_ponto_fixo(meio, f, g1, 40) - r2) < EPS) ini = meio;
        else fim = meio;
    }
    printf("Maior valor que converge para r2 em g1(x): %.8f\n\n", ini);
}