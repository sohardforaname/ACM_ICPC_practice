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
int a[N];
int mp[N][N];
bool check(int x, int y, int n)
{
    return x > 0 && x < n + 1 && y > 0 && y < n + 1 && y <= x;
}
const int dir[4][2] = { { 0, -1 }, { -1, 0 }, { 1, 0 }, { 0, 1 } };
int dfs(int x, int y, int div, int n, int num)
{
    mp[x][y] = num;
    if (div == 1) {
        return 0;
    }
    for (int i = 0; i < 4; ++i) {
        int dx = x + dir[i][0];
        int dy = y + dir[i][1];
        if (check(dx, dy, n) && !mp[dx][dy]) {
            return dfs(dx, dy, div - 1, n, num);
        }
    }
}

void solve()
{
    int n;
    io(n);
    io(io.make(a, 1, n + 1));
    memset(mp, 0, sizeof(mp));
    for (int i = 1; i <= n; ++i) {
        mp[i][i] = a[i];
    }
    //sort(p + 1, p + n + 1);
    for (int i = 1; i <= n; ++i) {
        dfs(i, i, a[i], n, a[i]);
    }
    for (int i = 1; i <= n; ++i) {
        wio(mp[i], 1, i + 1, ' ');
    }
}

MAIN_FUNC
