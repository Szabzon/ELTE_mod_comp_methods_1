#include <string>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;


template<typename V, typename U>
struct Temperature
{
    //default temperature unit is Celsius
    //all units will be converted to Celsius
    //all operations will be computed usint the Celsius value of the temperatures

    V v; // v as value, this is the value of the temperature
    U u; // u as unit, this is the unit of the temperature
    /*
    Temperature<V,U>& operator=(Temperature<V,U> const& a){
        return a;
    }
    */
    // this is the function which converts the temperature to C
    Temperature<V,U>& convert_to_C(){
        if (u=="C"){
            v+=0;
            u="C";
        }
        else if (u=="K"){
            v-=273.15;
            u="C";
        }
        else if (u=="F"){
            v=(v-32)/1.8;
            u="C";
        }
        else if (u=="R"){
            v=(v-491.67)/1.8;
            u="C";
        }
        else if (u=="De"){
            v=(v+100)/1.5;
            u="C";
        }
        else if (u=="Ro"){
            v=(v-7.5)/0.525;
            u="C";
        }
        return *this;
    }
    
    // this is the function which converts the temperature to the given unit
    //template<typename W>
    Temperature<V,U>& convert_from_C(string w){    // w is the unit to convert to
        if (w=="C"){
            v+=0;
            u="C";
        }
        else if (w=="K"){
            v+=273.15;
            u="K";
        }
        else if (w=="F"){
            v=v*1.8+32;
            u="F";
        }
        else if (w=="R"){
            v=v*1.8+491.67;
            u="R";
        }
        else if (w=="De"){
            v=v*1.5-100;
            u="De";
        }
        else if (w=="Ro"){
            v=v*0.525+7.5;
            u="Ro";
        }
        return *this;
    }
    
    // this function brings together the conversions
    Temperature<V,U>& convert(string w){
        *this=convert_to_C();
        *this=convert_from_C(w);
        /*v=convert_to_C1(v,u);
        u="C";
        v=convert_from_C1(v,u,w);
        u=w;*/
        return *this;
    }

    //---------Operators---------
    
    // addition assignment
    Temperature<V,U>& operator+=(Temperature<V,U> const& a){
        Temperature<V,U> b=a;
        b=convert1(b,u);
        v+=b.v;
        return *this;
    }
};

// this is the function which converts the temperature to C
template<typename V, typename U>
Temperature<V,U> convert_to_C1(Temperature<V,U> const& a){
    V v=a.v;
    U u=a.u;
    if (u=="C"){
        v+=0;
        u="C";
    }
    else if (u=="K"){
        v-=273.15;
        u="C";
    }
    else if (u=="F"){
        v=(v-32)/1.8;
        u="C";
    }
    else if (u=="R"){
        v=(v-491.67)/1.8;
        u="C";
    }
    else if (u=="De"){
        v=(v+100)/1.5;
        u="C";
    }
    else if (u=="Ro"){
        v=(v-7.5)/0.525;
        u="C";
    }
    else{
        cout<<"\nHIBA!\n";
    }
    return Temperature<V,U>{v,u};
}

// this is the function which converts the temperature to the given unit
template<typename V, typename U>
Temperature<V,U> convert_from_C1(Temperature<V,U> const& a, string w){
    V v=a.v;
    U u=a.u;
    if (w=="C"){
        v+=0;
        u="C";
    }
    else if (w=="K"){
        v+=273.15;
        u="K";
    }
    else if (w=="F"){
        v=v*1.8+32;
        u="F";
    }
    else if (w=="R"){
        v=v*1.8+491.67;
        u="R";
    }
    else if (w=="De"){
        v=v*1.5-100;
        u="De";
    }
    else if (w=="Ro"){
        v=v*0.525+7.5;
        u="Ro";
    }
    return Temperature<V,U>{v,u};
}

// this function brings together the conversions
template<typename V, typename U>
Temperature<V,U> convert1(Temperature<V,U> const& a, string w){    // w is the unit to convert to
    Temperature<V,U> b=a;
    b=convert_to_C1(b);
    b=convert_from_C1(b,w);
    return b;
}