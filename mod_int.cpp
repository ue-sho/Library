constexpr int mod = 1000000007;
class mint {
public:
    ll x;
    constexpr mint(long long x=0) : x((x % mod + mod) % mod) {}
    constexpr mint operator-() const { 
      return mint(-x);
    }
    constexpr mint& operator+=(const mint a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    constexpr mint& operator-=(const mint a) {
        if ((x += mod-a.x) >= mod) x -= mod;
        return *this;
    }
    constexpr mint& operator*=(const mint a) {
        (x *= a.x) %= mod;
        return *this;
    }
    constexpr mint operator+(const mint a) const {
        mint res(*this);
        return res+=a;
    }
    constexpr mint operator-(const mint a) const {
        mint res(*this);
        return res-=a;
    }
    constexpr mint operator*(const mint a) const {
        mint res(*this);
        return res*=a;
    }
    constexpr mint pow(ll t) const {
        if (!t) return 1;
        mint a = pow(t>>1);
        a *= a;
        if (t&1) a *= *this;
        return a;
    }

    // for prime mod
    constexpr mint inv() const {
        return pow(mod-2);
    }
    constexpr mint& operator/=(const mint a) {
        return (*this) *= a.inv();
    }
    constexpr mint operator/(const mint a) const {
        mint res(*this);
        return res/=a;
    }
    friend ostream& operator<<(ostream& os, const mint& a){
        os << a.x;
        return os;
    }
};

//逆元
ll mod_inv(ll a){
    
    ll b = mod, u = 1, v = 0;
    while(b){
        ll t = a / b;
        a -= t * b; 
        swap(a, b);
        u -= t * v; 
        swap(u, v);
    }
    u %= mod;
    if (u < 0){
        u += mod;
    } 
    return u;
}