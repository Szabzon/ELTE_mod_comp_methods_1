template<typename T>
struct Vector2d
{
    T x, y;

    Vector2d<T>& operator+=(Vector2d<T> const& v){
        x+=v.x; y+=v.y;
        return *this;
    }
    Vector2d<T>& operator-=(Vector2d<T> const& v){
        x-=v.x; y-=v.y;
        return *this;
    }
    
    template<typename S>
    Vector2d<T>& operator*=(S scalar){
        x*=scalar; y*=scalar;
        return *this;
    }
    template<typename S>
    Vector2d<T>& operator/=(S scalar){
        x/=scalar; y/=scalar;
        return *this;
    }
    template<typename S>
    Vector2d<T>& forg(S fi){
        T x1=cos(fi)*x-sin(fi)*y;
        T y1=sin(fi)*x+cos(fi)*y;
        x=x1;
        y=y1;
        return *this;
    }
    Vector2d<T>& tukrozesx(){
        x=-x;
        y=y;
        return *this;
    }
    Vector2d<T>& tukrozesy(){
        x=x;
        y=-y;
        return *this;
    }
    Vector2d<T>& tukrozesxy(){
        x=-x;
        y=-y;
        return *this;
    }
    Vector2d<T>& norm(){
        T l1=1/sqrt(x*x+y*y);
        x*=l1;
        y*=l1;
        return *this;
    }
    
};


template<typename T>
Vector2d<T> operator+(Vector2d<T> const& a, Vector2d<T> const& b){
    return Vector2d<T>{a.x+b.x, a.y+b.y};
}
template<typename T>
Vector2d<T> operator-(Vector2d<T> const& a, Vector2d<T> const& b){
    return Vector2d<T>{a.x-b.x, a.y-b.y};
}

template<typename T, typename S>
Vector2d<T> operator*(Vector2d<T> const& a, S scalar){
    return Vector2d<T>{a.x*scalar, a.y*scalar};
}
template<typename S, typename T>
Vector2d<T> operator*(S scalar, Vector2d<T> const& a){
    return Vector2d<T>{a.x*scalar, a.y*scalar};
}
template<typename T, typename S>
Vector2d<T> operator/(Vector2d<T> const& a, S scalar){
    return Vector2d<T>{a.x/scalar, a.y/scalar};
}
template<typename T>
T operator*(Vector2d<T> const& a, Vector2d<T> const& b){
    T sz=a.x*b.x+a.y*b.y;
    return sz;
}
template<typename T>
T operator%(Vector2d<T> const& a, Vector2d<T> const& b){
    T ksz=a.x*b.y-a.y*b.x;
    return ksz;
}
template<typename T>
T length(Vector2d<T> const& a){
    T l=sqrt(a.x*a.x+a.y*a.y);
    return l;
}
template<typename T>
T angle(Vector2d<T> const& a,Vector2d<T> const& b){
    return acos((a*b)/(length(a)*length(b)));
}

