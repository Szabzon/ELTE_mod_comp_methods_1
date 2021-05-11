#include <vector>
using namespace std;

template<typename V>
struct Temperature
{
    //default temperature unit is Celsius
    //all units will be converted to Celsius
    //all operations will be computed using the Celsius value of the temperatures

    V v; // v as value, this is the value of the temperature
    string u; // u as unit, this is the unit of the temperature

    // this is the function which converts the temperature to C
    Temperature<V>& convert_to_C(){

        string u1="C";
        string u2="K";
        string u3="F";
        string u4="R";
        string u5="De";
        string u6="Ro";

        string w=u;

        bool b1=w==u1;
        bool b2=w==u2;
        bool b3=w==u3;
        bool b4=w==u4;
        bool b5=w==u5;
        bool b6=w==u6;

        if (b1){
            v+=0;
            u=u1;
        }
        else if (b2){
            v-=273.15;
            u=u1;
        }
        else if (b3){
            v=(v-32)/1.8;
            u=u1;
        }
        else if (b4){
            v=(v-491.67)/1.8;
            u=u1;
        }
        else if (b5){
            v=(v+100)/1.5;
            u=u1;
        }
        else if (b6){
            v=(v-7.5)/0.525;
            u=u1;
        }
        else{
            cout<<"\nError\n";
    }
        return *this;
    }
    
    // this is the function which converts the temperature to the given unit
    //template<typename W>
    Temperature<V>& convert_from_C(string w){    // w is the unit to convert to
        
        string u1="C";
        string u2="K";
        string u3="F";
        string u4="R";
        string u5="De";
        string u6="Ro";

        bool b1=w==u1;
        bool b2=w==u2;
        bool b3=w==u3;
        bool b4=w==u4;
        bool b5=w==u5;
        bool b6=w==u6;

        if (b1){
            v+=0;
            u=u1;
        }
        else if (b2){
            v+=273.15;
            u=u2;
        }
        else if (b3){
            v=v*1.8+32;
            u=u3;
        }
        else if (b4){
            v=v*1.8+491.67;
            u=u4;
        }
        else if (b5){
            v=v*1.5-100;
            u=u5;
        }
        else if (b6){
            v=v*0.525+7.5;
            u=u6;
        }
        else{
            cout<<"\nError\n";
    }
        return *this;
    }
    
    // this function brings together the conversions
    Temperature<V>& convert(string w){
        *this=convert_to_C();
        *this=convert_from_C(w);
        return *this;
    }

    //---------Operators---------
    
    // addition assignment
    Temperature<V>& operator+=(Temperature<V> const& a){
        Temperature<V> b=a;
        b=convert1(b,u);
        v+=b.v;
        return *this;
    }

    // subtraction assignment
    Temperature<V>& operator-=(Temperature<V> const& a){
        Temperature<V> b=a;
        b=convert1(b,u);
        v-=b.v;
        return *this;
    }

    // overload the operator<
    bool operator<(const Temperature<V> &a) const{
        return convert_to_C1(*this).v<convert_to_C1(a).v;
    }

    // overload the operator>
    bool operator>(const Temperature<V> &a) const{
        return convert_to_C1(*this).v>convert_to_C1(a).v;
    }
};

// this is the function which converts the temperature to C
template<typename V>
Temperature<V> convert_to_C1(Temperature<V> const& a){
    
    V v=a.v;
    string u=a.u;

    string u1="C";
    string u2="K";
    string u3="F";
    string u4="R";
    string u5="De";
    string u6="Ro";

    bool b1=u==u1;
    bool b2=u==u2;
    bool b3=u==u3;
    bool b4=u==u4;
    bool b5=u==u5;
    bool b6=u==u6;

    if (b1){
        v+=0;
        u=u1;
    }
    else if (b2){
        v-=273.15;
        u=u1;
    }
    else if (b3){
        v=(v-32)/1.8;
        u=u1;
    }
    else if (b4){
        v=(v-491.67)/1.8;
        u=u1;
    }
    else if (b5){
        v=(v+100)/1.5;
        u=u1;
    }
    else if (b6){
        v=(v-7.5)/0.525;
        u=u1;
    }
    else{
        cout<<"\nError\n";
    }
    return Temperature<V>{v,u};
}

// this is the function which converts the temperature to the given unit
template<typename V>
Temperature<V> convert_from_C1(Temperature<V> const& a, string w){
    
    V v=a.v;
    string u=a.u;

    string u1="C";
    string u2="K";
    string u3="F";
    string u4="R";
    string u5="De";
    string u6="Ro";

    bool b1=w==u1;
    bool b2=w==u2;
    bool b3=w==u3;
    bool b4=w==u4;
    bool b5=w==u5;
    bool b6=w==u6;

    if (b1){
        v+=0;
        u=u1;
    }
    else if (b2){
        v+=273.15;
        u=u2;
    }
    else if (b3){
        v=v*1.8+32;
        u=u3;
    }
    else if (b4){
        v=v*1.8+491.67;
        u=u4;
    }
    else if (b5){
        v=v*1.5-100;
        u=u5;
    }
    else if (b6){
        v=v*0.525+7.5;
        u=u6;
    }
    else{
        cout<<"\nError\n";
    }
    return Temperature<V>{v,u};
}

// this function brings together the conversions
template<typename V>
Temperature<V> convert1(Temperature<V> const& a, string w){    // w is the unit to convert to
    Temperature<V> b=a;
    b=convert_to_C1(b);
    b=convert_from_C1(b,w);
    return b;
}

// Operators

// addition
template<typename V>
Temperature<V> operator+(Temperature<V> const& a, Temperature<V> const& b){
    Temperature<V> c=b;
    c=convert1(c,a.u);
    c.v+=a.v;
    return c;
}

// subtraction
template<typename V>
Temperature<V> operator-(Temperature<V> const& a, Temperature<V> const& b){
    Temperature<V> c=b;
    c=convert1(c,a.u);
    c.v=a.v-c.v;
    return c;
}


// sort
template<typename V>
vector<Temperature<V>> sort1(vector<Temperature<V>> const& l1, bool order=true){
    int n=l1.size();
    vector <Temperature<V>> l2=l1;
    Temperature<V> temp;
    if (order==true){ // from low to high
        for (int i=0;i<n;i++){ // do the sorting
            for (int j=i+1;j<n;j++){
                if (l2[i]>l2[j]){
                    temp=l2[i];
                    l2[i]=l2[j];
                    l2[j]=temp;
                }
            }
        }
    }
    else{ // from high to low
        for (int i=0;i<n;i++){
            for (int j=i+1;j<n;j++){
                if (l2[i]<l2[j]){
                    temp=l2[i];
                    l2[i]=l2[j];
                    l2[j]=temp;
                }
            }
        }
    }
    return l2;
}

