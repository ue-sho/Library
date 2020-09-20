// Binary Indexed Tree (Fenwick Tree)
// https://youtu.be/lyHk98daDJo?t=7960
// まだ理解していない

#include <vector>

using namespace std;

template <typename T>
class BIT {
public:
    vector<T> d;

    BIT(int n = 0) : d(n + 1) {}

    void add(int a, T x)
    {
        for (int i = a; i < (int)d.size(); i += i & -i) {
            d[i] += x;
        }
    }

    T sum(int a)
    {
        T ret = 0;
        for (int i = a; i > 0; i -= i & -i) {
            ret += d[i];
        }
        return ret;
    }

    T sum(int l, int r)
    {
        return sum(r - 1) - sum(l - 1);
    }
};
