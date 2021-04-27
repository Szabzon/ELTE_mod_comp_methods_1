#include <iostream>
#include "temperature.h"
#include <string>
#include <string.h>

using namespace std;

int main(int, char**) {
    Temperature <double,string> t1{100,"C"};
    /*
    t1.v=10;
    t1.u="C";
    */

    t1.convert("Ro");

    cout<<"maga a t1 hom: "<<t1.v<<" "<<t1.u<<"\n";

    //std::cout<<"maga a t2 hom: "<<t2.v<<" "<<t2.u<<"\n";

}