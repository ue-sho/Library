//最大公約数
template <class T>
T gcd(T a, T b) {

    if(b == 0){
        return a;
    }
    else{
        gcd(b, a%b);
    }
}

//最小公倍数
template <class T>
T lcm(T a, T b){

    T g = gcd(a, b);

    return a / g * b;
}