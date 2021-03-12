#include <iostream>

using namespace std; // hogy ne kelljen mindig kiírni azt a plusz pár betűt

template<typename T> // ezzel még csak nézegettem pár dolgot az elején, ellenőriztem magam, ez csak egy sima négyzetre emelés függvény
T sq(T x){return x*x;};


template<typename F, typename G, typename T> // megírom template-eket
T newton_iter(F f, G g, T x_n){ // ez a newtoni iterációt végő függvényem, ahol f és g az adott függvény és a deriváltja
    double x_n_1; // létrehozom az x_n-1 változót
    int i=0; // bevezeket egy ciklusváltozó szerűséget, ez csak arra van, ha véletlenül nem konvergálna, akkor ne akadjon ki,
            // de később látszani fog, hogy mire jó pontosan
    do{ // egy do-while ciklussal oldottam meg a dolgot
        x_n_1=x_n; // elmentem az előző x-et
        x_n=x_n-f(x_n)/g(x_n); // kiszámolom a következő x-et
        //cout<<x_n<<"\n"; // kiirattam debugolás céljából, hogy épp milyen értéknél tart
        //cout<<abs(x-x_n_1)<<"\n\n";
        i++; // megnövelem i-t
    }while(abs(x_n-x_n_1)>0.00000000000001 && i<1000); // addig megy a ciklus, amíg vagy tetszőlegesen be nem konvergál, 
                                                // azaz egymást követő két x különbsége tetszőlegesen kicsi, vagy addig, 
                                                // amíg egy tetszőleges (most 1000) számot el nem ért a próbálkozások száma, 
                                                // ez azért van, hogy ne akadhasson ki, ha nem akarna konvergálni
    return x_n; // visszaadom megtalált értéket
}


int main(int, char**) { // ez a main függvényem
    cout.precision(23); // beállítom a kiírás pontosságát
    //cout<<"\nHelloka\n\n";
    //cout<<sq(24.738633753705965290237)<<"\n";
    cout<<newton_iter([](double x){ return x*x - 612.0; },[](double x){ return 2.0*x; }, 10.0)<<"\n"; // meghívom a fentebb megírt függvénéyem
}

// megjegyzés: próbálkoztam különböző technikákkal, hogy pontosabb értéket kapjak, de egyik sem volt igazán célravezető, viszont 
// ez az eredmény is elég pontos szerintem