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
    
    // this is the function which converts the temperature to
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


};


// this is the function which converts the temperature to C
template<typename V, typename U>
V convert_to_C1(V v, U u){
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
    return v;
}

// this is the function which converts the temperature to
//template<typename W>


template<typename V, typename U>
V convert_from_C1(V v, U u, string w){  // w is the unit to convert to
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
        v=(v-7.5)/0.525;
        v=v*0.525+7.5;
        u="Ro";
    }
    return v;
}






/*

template<typename V, typename U>
    V atvalt1(Temperature<V,U> const& a){
        if (a.u=="C"){
            a.v+=0;
        }
        else if (a.u=="K"){
            a.v-=273.15;
        }
        else if (a.u=="F"){
            a.v=(v-32)/1.8;
        }
        else if (a.u=="R"){
            a.v=(v-491.67)/1.8;
        }
        else if (u=="De"){
            a.v=(a.v+100)/1.5;
        }
        else if (a.u=="Ro"){
            a.v=(v-7.5)/0.525;
        }
        return a.v;
    }
*/

/*
template<typename V, typename U>
V atvalt1(Temperature<V,U> const& a){
    if (a.u=="C"){
        a.v+=0;
        a.u="C";
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
    */

   /*
   string val=to_string(v);
    int i=0;
    for (i=0;i<val.length()){
        if (isdigit(val[i])==false){
            break;
             cout<<"The value of the temperature is not a number. Please correct it!";
        }
    }
    while (i<val.length() && isdigit(val[i])==true){
        i++;
    }
    if (i<val.length()){
        cout<<"The value of the temperature is not a number. Please correct it!";
    }
    */