#include <iostream>
#include "temperature.h"


using namespace std;

int main(int, char**) {
    Temperature <double> t1{0,"K"}; // létrehozás
    Temperature <double> t2{0,"F"};
    
    //műveletek, függvények tesztelése
    
    cout<<"a t1 hom: "<<t1.v<<" "<<t1.u<<"\n";
    cout<<"a t2 hom: "<<t2.v<<" "<<t2.u<<"\n";

    t1.convert("Ro");
    cout<<"a t1 hom: "<<t1.v<<" "<<t1.u<<"\n";
    t1.convert("K");

    Temperature <double> t3=t1+t2;
    cout<<"t1+t2: "<<t3.v<<" "<<t3.u<<"\n";
    t3=t1-t2;
    cout<<"t1-t2: "<<t3.v<<" "<<t3.u<<"\n";
    t1+=t2;
    cout<<"t1+=t2: "<<t1.v<<" "<<t1.u<<"\n";
    t1-=t2;
    t1-=t2;
    cout<<"t1-=t2: "<<t1.v<<" "<<t1.u<<"\n";


    vector <Temperature<double>> temps{{0,"C"},{0,"K"},{0,"F"}};
    vector <Temperature<double>> temps2=sort(temps,false); // rendezés

    int n=temps.size(); // a vektor kiíratása
    for (int i=0;i<n;i++){
        cout<<temps2[i].v<<" "<<temps2[i].u<<" ";
    }
}