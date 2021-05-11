#include <iostream>
#include "temperature.h"
#include <algorithm>

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
    vector <Temperature<double>> temps2=sort1(temps,false); // sort the vector by my own method

    cout<<"\nthe sorted temps vector with my method: ";
    int n=temps.size(); 
    for (int i=0;i<n;i++){
        cout<<temps2[i].v<<" "<<temps2[i].u<<", "; // print the sorted vector
    }
    cout<<"\nthe sorted temps vector using the algorithm library: ";
    sort(temps.begin(),temps.end(),greater<Temperature<double>>()); // sort the vector using the algorithm library 
    for (int i=0;i<n;i++){
        cout<<temps[i].v<<" "<<temps[i].u<<", "; // print the sorted vector
    }


}