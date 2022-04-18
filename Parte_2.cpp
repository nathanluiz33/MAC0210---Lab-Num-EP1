#include <iostream>
#include <math.h>
#include <iomanip>
#include <complex>
#include <cmath>
#include <assert.h>

using namespace std;

const double EPS = 1e-8;
const double PI = acos(-1);

typedef complex<double> cd;

/* newton: função que retorna um complex<double> sendo a raiz para onde
*  um ponto converge pelo Método de Newton. Caso não haja convergência, retorna cd(NAN, NAN)
*  x0 -> ponto inicial de iteracao, F -> função em que vamos utilizar o método
*  dF -> derivada de F, lim_iteracoes -> número máximo permitido de iteracoes do método
*/
cd newton(cd x0, cd (*F)(cd), cd (*dF)(cd), int lim_iteracoes){
    cd raiz = x0;

    while(abs(F(raiz)) > EPS && lim_iteracoes > 0){
        raiz = raiz - F(raiz) / dF(raiz);
        lim_iteracoes--;
    }

    if(lim_iteracoes == 0) return cd(NAN, NAN);

    return raiz;
}

// função sin(x)
cd evalf(cd x){
    return sin(x);
}

// derivada de sin(x)
cd evalDf(cd x){
    return cos(x);
}

// função x^3 - 1
cd evalf1(cd x){
    return pow(x, 3) - cd(1., 0.);
}

// derivada de x^3 - 1
cd evalDf1(cd x){
    return cd(3., 0.) * pow(x, 2);
}

/* newton_basins: função que imprime as coordenadas dos pontos
*  e para qual raiz esse ponto converge pelo método de Newton
*  l -> menor coordenada do grid, u -> maior coordenada do grid
*  p -> quantos pontos vai ter cada direção
*  vamos separar o grid [l, u] x [l, r] em p x p pontos
*/
void newton_basins(double l, double u, int p) {
    double step = (u - l) / p;
    for(double x = l; x <= u; x += step)
        for(double y = l; y <= u; y += step){
            cout << "(" << x << ", " << y << ") ";
            cout << newton(cd(x, y), evalf, evalDf, 1000) << "\n";
        }
}

int main() {
    freopen("output.txt", "w", stdout);
    newton_basins(-2, 2, 400);
    return 0;
}