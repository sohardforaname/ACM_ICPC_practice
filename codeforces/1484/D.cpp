#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;

struct ReadIO {
    int operator()(int& x)
    {
        return scanf("%d", &x);
    }
    int operator()(ll& x)
    {
        return scanf("%lld", &x);
    }
    int operator()(ull& x)
    {
        return scanf("%llu", &x);
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
    inline int getarray(T& arr, const size_t beg, const size_t end) //[beg, end)
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
    //[beg, end)
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

bool multi = 0;
const int N = 5e2 + 5;
const int M = 25;
struct node {
    int l, u, r, d;
    node() { }
    node(int _l, int _u, int _r, int _d)
        : l(_l)
        , u(_u)
        , r(_r)
        , d(_d)
    {
    }
    int minn()
    {
        return min({ l, u, r, d });
    }
};
node mp[N][N];
int ud[N][N];
int lr[N][N];
int minn[N][N][M];

bool check(int x, int y, int n, int m)
{
    return x > 0 && x < n + 1 && y > 0 && y < m + 1;
}

void solve()
{
    int n, m, st;
    io(n, m, st);
    memset(lr, 0x3f, sizeof(lr));
    memset(ud, 0x3f, sizeof(ud));
    for (int i = 1; i <= n; ++i) {
        io(io.make(lr[i], 1, m));
    }
    for (int i = 1; i < n; ++i) {
        io(io.make(ud[i], 1, m + 1));
    }
    if (st % 2) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                printf("-1%c", " \n"[j == m]);
            }
        }
        return;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            mp[i][j] = { lr[i][j - 1], ud[i - 1][j], lr[i][j], ud[i][j] };
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            minn[i][j][1] = mp[i][j].minn();
        }
    }
    for (int k = 2; k <= 10; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                int cnt = INF;
                for (int x = -k + 1; x < k; ++x) {
                    for (int y = -k + 1; y < k; ++y) {
                        if ((abs(x) + abs(y)) >= k) {
                            continue;
                        }
                        if ((abs(x) + abs(y)) % 2 == k % 2) {
                            continue;
                        }
                        if (!check(i + x, j + y, n, m)) {
                            continue;
                        }
                        cnt = min(cnt, mp[i + x][j + y].minn());
                    }
                }
                minn[i][j][k] = cnt + minn[i][j][k - 1];
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            printf("%d%c", minn[i][j][st / 2] * 2, " \n"[j == m]);
        }
    }
}

MAIN_FUNC

inline int popcount1(uint x)
{
    x = x - ((x >> 1) & 0x55555555);
    x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
    return ((x + (x >> 4) & 0xF0F0F0F) * 0x1010101) >> 24;
}
