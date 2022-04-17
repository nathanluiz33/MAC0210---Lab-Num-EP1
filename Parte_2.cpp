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

cd newton(cd x0, cd (*F)(cd), cd (*dF)(cd), int lim_iteracoes){
    cd raiz = x0;

    while(abs(F(raiz)) > EPS && lim_iteracoes > 0){
        raiz = raiz - F(raiz) / dF(raiz);
        lim_iteracoes--;
    }

    if(lim_iteracoes == 0) return cd(NAN, NAN);

    return raiz;
}

cd evalf(cd x){
    return sin(x);
}

cd evalDf(cd x){
    return cos(x);
}

cd evalf1(cd x){
    return pow(x, 3) - cd(1., 0.);
}

cd evalDf1(cd x){
    return cd(3., 0.) * pow(x, 2);
}

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