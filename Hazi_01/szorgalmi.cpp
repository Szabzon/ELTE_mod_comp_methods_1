#include <iostream>

using namespace std;


bool eldonto(double x_n, double x_n_1, int i){ // külön függvénybe kiszedtem az eddig a while hasában megadott feltételt
    bool retval;
    if (abs(x_n-x_n_1)>0.00000000000001 && i<1000){
        retval=true;
    }else{
        retval=false;
    }
    return retval;
}

template<typename F, typename G, typename T>
T newton_iter(F f, G g, T x_n){
    double x_n_1;
    int i=0;
    do{
        x_n_1=x_n;
        x_n=x_n-f(x_n)/g(x_n);
        i++;
    }while(eldonto(x_n, x_n_1, i)==true); // meghívom a while belsejében a külön efüggvényt, ami eldönti, hogy menjen-e tovább a ciklus
    return x_n;
}


int main(int, char**) {
    //cout<<"\nHelloka\n\n";
    cout.precision(23);
    cout<<newton_iter([](double x){ return x*x - 612.0; },[](double x){ return 2.0*x; }, 10.0)<<"\n";
}
