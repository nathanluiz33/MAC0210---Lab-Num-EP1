#include <iostream>
#include <math.h>
#include <iomanip>
#include <complex>
#include <cmath>
#include <assert.h>

using namespace std;

const double EPS = 1e-8;

typedef complex<double> cd;

cd newton_method(cd x0, cd (*F)(cd), cd (*dF)(cd), int lim_iteracoes){
    cd raiz = x0;

    while(abs(raiz) > EPS && lim_iteracoes > 0){
        cout << raiz << "\n";
        raiz = raiz + F(raiz) / dF(raiz);
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
    // using namespace complex_literals;
    cd z1 = 1. + 2i;
    cout << newton_method(z1, f, df, 1000);
    // cout << z1 << "\n";
    // cout << abs(z1) << "\n";
    // cout << imag(df(z1)) << "\n";
}