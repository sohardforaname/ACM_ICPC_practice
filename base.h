#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;

struct IO {
    int operator()(int& x)
    {
        return scanf("%d", &x);
    }
    int operator()(ll& x)
    {
        return scanf("%lld", &x);
    }
    int operator()(double& x)
    {
        return scanf("%lf", &x);
    }
    int operator()(char* s)
    {
        return scanf("%s", s);
    }
    int operator()(char& ch)
    {
        return scanf("%c", &ch);
    }

public:
    size_t readElement;

private:
    template <class T>
    inline int getarray(T& arr, const size_t beg, const size_t end)
    {
        int rtv = -1;
        readElement = 0;
        for (size_t i = beg; i < end && rtv; ++i, ++readElement)
            rtv = (*this)(arr[i]);
        return rtv;
    }

public:
    template <class T>
    static tuple<vector<T>&, size_t> make(
        vector<T>& vec, size_t size)
    {
        return move(make_tuple(ref(vec), size));
    }
    template <class T>
    inline int operator()(tuple<vector<T>&, size_t> tp)
    {
        auto& vec = get<0>(tp);
        auto len = get<1>(tp);

        vec.resize(len);
        return getarray(vec, 0, len);
    }

    //input a series of numbers and store them in an array
    template <class T>
    static tuple<T*, size_t, size_t> make(
        T* arr, size_t beg, size_t end)
    {
        return move(make_tuple(arr, beg, end));
    }
    template <class T>
    inline int operator()(tuple<T*, size_t, size_t> tp)
    {
        return getarray(get<0>(tp), get<1>(tp), get<2>(tp));
    }

    template <class T, class... Ts>
    int operator()(T&& x, Ts&&... y)
    {
        return (*this)(forward<T>(x)) + (*this)(y...);
    }
} io;
class WriteIO {

public:
    // output
    int w;
    void operator()(const int x, const char ch)
    {
        printf("%d%c", x, ch);
    }
    void operator()(const ll x, const char ch)
    {
        printf("%lld%c", x, ch);
    }
    void operator()(const char x, const char ch)
    {
        putchar(x);
    }
    void operator()(const double x, const char ch)
    {
        printf("%.*lf", w, x);
        putchar(ch);
    }
    template <class Iter>
    void operator()(Iter beg, Iter end, const char ch)
    {
        for (auto it = beg; it != end; ++it)
            (*this)(*it, ch);
        putchar('\n');
    }
    void operator()(const char* s, const char ch)
    {
        printf("%s%c", s, ch);
    }
    template <class T>
    void operator()(const T* arr, int beg, int end, const char ch)
    {
        for (auto it = beg; it != end; ++it)
            (*this)(arr[it], ch);
        putchar('\n');
    }
    WriteIO()
        : w(6)
    {
    }
} wio; // class IO
struct util {
private:
    template <class T>
    constexpr static T get()
    {
        return 63;
    }
    constexpr static int get()
    {
        return 31;
    }

public:
    template <class T>
    static constexpr void cmax(T& a, const T& b)
    {
        if (a < b)
            a = b;
    }
    template <class T>
    static constexpr void cmin(T& a, const T& b)
    {
        if (b < a)
            a = b;
    }
    template <class T>
    static constexpr void addm(T& a, const T& b, const T& mod)
    {
        a += b - mod;
        a += (a >> get<T>()) & mod;
    }
} util; // class util
struct math {
    static constexpr ll pow(ll a, ll b, const ll& p)
    {
        ll res = 1;
        while (b) {
            if (b & 1)
                res = res * a % p;
            a = a * a % p;
            b >>= 1;
        }
        return res;
    }
    static constexpr ll mul(ll a, ll b, const ll& p)
    {
        ll res = 0;
        while (b) {
            if (b & 1)
                util.addm(res, a, p);
            util.addm(a, a, p);
            b >>= 1;
        }
        return res;
    }
    static constexpr ll gcd(ll a, ll b)
    {
        return !b ? a : gcd(b, a % b);
    }
} math; // class math
const ll mod98 = 998244353;
const ll mod17 = 1e9 + 7;
const ll mod19 = 1e9 + 9;
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;

#define MAIN_FUNC    \
    int main()       \
    {                \
        int t;       \
        if (multi)   \
            io(t);   \
        else         \
            t = 1;   \
        while (t--)  \
            solve(); \
        return 0;    \
    }