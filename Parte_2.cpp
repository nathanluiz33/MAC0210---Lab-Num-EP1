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

cd newton_method(cd x0, cd (*F)(cd), cd (*dF)(cd), int lim_iteracoes){
    cd raiz = x0;

    while(abs(F(raiz)) > EPS && lim_iteracoes > 0){
        raiz = raiz - F(raiz) / dF(raiz);
        lim_iteracoes--;
    }

    assert(lim_iteracoes > 0);

    return raiz;
}

cd f(cd x){
    return sin(x);
}

cd df(cd x){
    return cos(x);
}

int main(){
    for(double x = -20; x <= 20; x += 1e-1)
        for(double y = -20; y <= 20; y += 1e-1){
            cout << "(" << x << ", " << y << ") ";
            cout << newton_method(cd(x, y), f, df, 1000) << "\n";
        }
}