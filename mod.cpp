const int mod = 1000000007;
struct mint {
    ll x;
    mint(ll x=0) : x((x%mod+mod)%mod) {}
    mint operator-() const { 
      return mint(-x);
    }
    mint& operator+=(const mint a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator-=(const mint a) {
        if ((x += mod-a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator*=(const mint a) {
        (x *= a.x) %= mod;
        return *this;
    }
    mint operator+(const mint a) const {
        mint res(*this);
        return res+=a;
    }
    mint operator-(const mint a) const {
        mint res(*this);
        return res-=a;
    }
    mint operator*(const mint a) const {
        mint res(*this);
        return res*=a;
    }
    mint pow(ll t) const {
        if (!t) return 1;
        mint a = pow(t>>1);
        a *= a;
        if (t&1) a *= *this;
        return a;
    }

    // for prime mod
    mint inv() const {
        return pow(mod-2);
    }
    mint& operator/=(const mint a) {
        return (*this) *= a.inv();
    }
    mint operator/(const mint a) const {
        mint res(*this);
        return res/=a;
    }
};


//modありのべき乗　xのn乗
ll mod_pow(ll x, ll n){

    ll ret = 1;
    while(n > 0){
        if(n & 1){
            (ret *= x) %= mod;
        }
        (x *= x) %= mod;
        n >>= 1;
    }
    return ret;
}

//逆元　(割り算をmodしていきたいときに使用)
//modの世界では割り算に余りはない
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

// a ÷ b mod. MOD を計算してみる
int main() {

    long long a = 12345678900000;
    long long b = 100000;

    // a を 10000000007 で割ってから b の逆元をかけて計算
    a %= mod;
    cout << a * mod_inv(b) % mod << endl;
}