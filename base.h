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

class IO
{
private:
    const int MAXBUF = 1 << 20;
    char buf[1 << 20], *fh, *ft;
    int f;
    inline char gc()
    {
        if (fh == ft)
        {
            ft = (fh = buf) + fread(buf, 1, MAXBUF, stdin);
            if (fh == ft)
                return EOF;
        }
        return *fh++;
    }
    bool isdigit(const char &ch)
    {
        return ch >= '0' && ch <= '9';
    }
    bool isblank(const char &ch)
    {
        return ch < '_' || ch > '~';
    }
    template <class T>
    inline int _read(T &x)
    {
        char c;
        for (c = gc(); c != EOF && !isdigit(c); c = gc())
            ;
        if (c == EOF)
            return c;
        f = 1;
        if (c == '-')
            f = -f;
        for (x = 0; c != EOF && isdigit(c); c = gc())
            x = x * 10ll + c - '0';
        x *= f;
        return c;
    }
    inline int _read(double &x)
    {
        ll i;
        char c = _read(i);
        double p = 0.1, s = 0;
        if (c == EOF)
            return -1;
        x = i;
        if (c == '.')
            for (c = gc(); c != EOF && isdigit(c); c = gc())
                s += p * (1.0 * c - '0'), p *= 0.1;
        x += s * f;
        return c;
    }
    inline int _read(char *s)
    {
        char c;
        for (c = gc(); c != EOF && isblank(c); c = gc())
            ;
        if (c == EOF)
            return c;
        for (; c != EOF && !isblank(c); c = gc())
            *(s++) = c;
        *s = 0;
        return c;
    }
    template <class T>
    inline void _write(const T &x)
    {
        if (x > 9)
            _write(x / 10);
        putchar(x % 10 + '0');
    }

public:
    int operator()(char *x)
    {
        return _read(x);
    }
    template <class T>
    int operator()(T &x)
    {
        return _read(x);
    }
    template <class T, class... Ts>
    int operator()(T &x, Ts &... y)
    {
        if (_read(x) == -1)
            return -1;
        return (*this)(y...);
    }
    template <class T>
    inline void operator()(const T &x, const char &ch)
    {
        if (x < 0)
            putchar('-');
        _write(x > 0 ? x : -x);
        putchar(ch);
    }
    inline void operator()(const double &x, const int &w, const char &ch)
    {
        printf("%.*lf", w, x);
        putchar(ch);
    }
    inline void operator()(const char *s, const char &ch)
    {
        printf("%s", s);
        putchar(ch);
    }
    IO() : ft(NULL), fh(NULL) {}
} io; //class IO
struct util
{
private:
    template <class T>
    static T get()
    {
        return 63;
    }
    static int get()
    {
        return 31;
    }

public:
    template <class T>
    static inline void cmax(T &a, const T &b)
    {
        if (a < b)
            a = b;
    }
    template <class T>
    static inline void cmin(T &a, const T &b)
    {
        if (b < a)
            a = b;
    }
    template <class T>
    static inline void addm(T &a, const T &b, const T &mod)
    {
        a += b - mod;
        a += (a >> get<T>()) & mod;
    }
} util; // class util
struct math
{
    static inline ll pow(ll a, ll b, const ll &p)
    {
        ll res = 1;
        while (b)
        {
            if (b & 1)
                res = res * a % p;
            a = a * a % p;
            b >>= 1;
        }
        return res;
    }
    static inline ll mul(ll a, ll b, const ll &p)
    {
        ll res = 0;
        while (b)
        {
            if (b & 1)
                util.addm(res, a, p);
            util.addm(a, a, p);
            b >>= 1;
        }
        return res;
    }
    static inline ll gcd(ll a, ll b)
    {
        return !b ? a : gcd(b, a % b);
    }
} math; // class math
struct debug
{
    template <class T>
    inline void operator()(const vector<T> &v)
    {
        for (int i = 0; i < v.size(); ++i)
            io(v[i], i == v.size() - 1 ? '\n' : ' ');
    }
    template <class T>
    inline void operator()(const T *v, size_t sz)
    {
        for (int i = 1; i <= sz; ++i)
            io(v[i], i == sz ? '\n' : ' ');
    }
    template <class T>
    inline void operator()(const T *v, size_t beg, size_t end)
    {
        for (int i = beg; i <= end; ++i)
            io(v[i], i == end ? '\n' : ' ');
    }
    template <class T>
    inline void operator()(const T &v)
    {
        io(v, '\n');
    }
    inline void operator()(const double &v, const int &w)
    {
        io(v, w, '\n');
    }
}; // class debug
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