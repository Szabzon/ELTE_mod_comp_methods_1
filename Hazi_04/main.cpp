#include <iostream>
#include <math.h>
#include <fstream>
#include <vector>
#include <string>

using namespace std;


double f1(double t, double y){
    return 1+t*t;
}

double f_analytical(double t0, double y){
    return y+y*y*y/3-t0+t0*t0*t0/3;
}

vector <double> newton_odeint(double (*f)(double,double), double y0, double t0, double tbound, double h){
    double l,n,x;
    l=tbound-t0;
    n=l/h;
    int m=(int) n;
    vector <double> y(m); 
    y[0]=y0;
    x=t0;
    for (int i=1;i<m;i++){
        y[i]=y[i-1]+h*f(x,y[i-1]);
        x+=h;
    }
    return y;
}

template<typename State, typename T, typename RHS>
auto solve_rk4(State y0, T t0, T t1, T h, RHS f){
    T t = t0; State y = y0;
    while(t < t1){
        if(t + h > t1){ h = t1 - t; }
        State k1 = f(t, y);
        State k2 = f(t + h * (T)0.5, y + (h * (T)0.5) * k1);
        State k3 = f(t + h * (T)0.5, y + (h * (T)0.5) * k2);
        State k4 = f(t + h, y + h * k3);
        y = y + (k1 + k4 + (T)2 * (k2 + k3)) * (h / (T)6);
        t = t + h;
    }
    return y;
}

void kiirat(){
    ofstream ofile;
    ofile.open ("output.txt");
    ofile.precision(16);
    cout.precision(16);
    double y0, t0, tbound, h, y1,y2,y3;
    int n;
    vector <double> y;
    string s;
    y0=0;
    t0=0;
    tbound=10;
    for(int i=1;i<6;i++){
        h=pow(10,-i);

        s=to_string(h);
        n=s.length();
        for (int j=0;j<10-n;j++){
            s+=" ";
        }
        y = newton_odeint(f1, y0, t0, tbound, h);
        int len=y.size();
        y1=y[len-1];

        y2=solve_rk4(y0, t0, tbound, h, f1);

        y3=f_analytical(t0,tbound);

        ofile<<"A lepes hossza: h="<<s<<"   ";
        ofile<<y1<<"    ";
        ofile<<y2<<"    ";
        ofile<<y3<<"\n\n";

        cout<<"A lepes hossza: h="<<s<<"    ";
        cout<<y1<<"    ";
        cout<<y2<<"    ";
        cout<<y3<<"\n\n";
    }
    ofile.close();
}


int main(int, char**) {
    kiirat();
}
