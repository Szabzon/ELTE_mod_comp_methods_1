#include <iostream>
#include "vector2.h"

int main(int, char**) {
    double  pi=3.14159265358979323846;
    double sc=10.0;
    Vector2d<double> v={2.0,3.0};
    Vector2d<double> w={4.0,5.0};

    std::cout<<"maga a v vektor: "<<v.x<<" "<<v.y<<"\n";
    std::cout<<"maga a w vektor: "<<w.x<<" "<<w.y<<"\n";

    // a structba építettt műveletek tesztelése

    v+=w;
    std::cout<<"osszeadas: "<<v.x<<" "<<v.y<<"\n";

    v={2.0,3.0};
    v-=w;
    std::cout<<"kivonas: "<<v.x<<" "<<v.y<<"\n";


    v={2.0,3.0};
    v*=sc;
    std::cout<<"szorzas skalarral: "<<v.x<<" "<<v.y<<"\n";
    
    v={2.0,3.0};
    v/=sc;
    std::cout<<"osztas skalarral: "<<v.x<<" "<<v.y<<"\n";

    v={2.0,3.0};
    double fi=pi/3;
    v.forg(fi);
    std::cout<<"forgatas: "<<v.x<<" "<<v.y<<"\n";

    v={2.0,3.0};
    v.tukrozesx();
    std::cout<<"tukrozes y tengelyre: "<<v.x<<" "<<v.y<<"\n";

    v={2.0,3.0};
    v.tukrozesy();
    std::cout<<"tukrozes x tengelyre: "<<v.x<<" "<<v.y<<"\n";

    v={2.0,3.0};
    v.tukrozesxy();
    std::cout<<"tukrozes kozeppontosan: "<<v.x<<" "<<v.y<<"\n";

    v={2.0,3.0};
    v.norm();
    std::cout<<"normalizalas: "<<v.x<<" "<<v.y<<"\n";
    
    std::cout<<"\n\n";

    // a külön definiált műveletek, függvények tesztelése

    v={2.0,3.0};
    v=v+w;
    std::cout<<"osszeadas: "<<v.x<<" "<<v.y<<"\n";

    v={2.0,3.0};
    v=v-w;
    std::cout<<"kivonas: "<<v.x<<" "<<v.y<<"\n";

    v={2.0,3.0};
    v=v*sc;
    std::cout<<"szorzas skalarral jobbrol: "<<v.x<<" "<<v.y<<"\n";

    v={2.0,3.0};
    v=sc*v;
    std::cout<<"szorzas skalarral balrol: "<<v.x<<" "<<v.y<<"\n";

    v={2.0,3.0};
    v=v/sc;
    std::cout<<"osztas skalarral: "<<v.x<<" "<<v.y<<"\n";

    v={2.0,3.0};
    std::cout<<"skalarszorzat: "<<v*w<<"\n";

    std::cout<<"vektorszorzat: "<<v%w<<"\n";

    std::cout<<"hosszusag: "<<length(v)<<"\n";

    std::cout<<"bezart szog: "<<angle(v,w)<<"\n";

}
