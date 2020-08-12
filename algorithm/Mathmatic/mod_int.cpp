constexpr int mod = 1000000007;
class mint {
public:
    long long x;
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
    constexpr mint pow(int t) const {
        if (!t) return 1;
        mint a = pow(t>>1);
        a *= a;
        if (t&1) a *= *this;
        return a;
    }
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