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
    char buf[1 << 20], *fh = NULL, *ft = NULL;
    int f;
    inline char gc()
    {
        if (fh == ft)
            ft = (fh = buf) + fread(buf, 1, MAXBUF, stdin);
        return *fh++;
    }
    bool isdigit(const char &ch)
    {
        return ch >= '0' && ch <= '9';
    }
    bool isblank(const char &ch)
    {
        return ch == '\n' || ch == '\t' || ch == ' ' || ch == '\r';
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
                res = (res + a) % p;
            a = (a + a) % p;
            b >>= 1;
        }
        return res;
    }
    static inline ll gcd(ll a, ll b)
    {
        return !b ? a : gcd(b, a % b);
    }
} math; // class math
struct util
{
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
    static inline void addm(T &a, const T &mod)
    {
        a >= mod &&a -= mod;
    }
} util; // class util
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

const int N = 2e1 + 5, M = 1e1;
bool multi = 0;

int trie[N][M], fail[N];
bool f[N];
int cnt;
struct Mat
{
    ll mat[N][N];
    Mat()
    {
        memset(mat, 0, sizeof(mat));
    }
};

void insert(char *s, int len)
{
    int root = 0;
    for (int i = 0; i < len; ++i)
    {
        int nxt = s[i] - '0';
        if (!trie[root][nxt])
            trie[root][nxt] = ++cnt;
        root = trie[root][nxt];
    }
    f[root] = 1;
}
void getfail()
{
    queue<int> q;
    for (int i = 0; i < M; ++i)
        if (trie[0][i])
            q.push(trie[0][i]), fail[trie[0][i]] = 0;
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        if (f[fail[now]])
            f[now] = 1;
        for (int i = 0; i < M; ++i)
        {
            if (trie[now][i])
            {
                q.push(trie[now][i]);
                fail[trie[now][i]] = trie[fail[now]][i];
            }
            else
                trie[now][i] = trie[fail[now]][i];
        }
    }
}
ll n, m, mod;
Mat mul(const Mat &a, const Mat &b, int n)
{
    Mat res;
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= n; ++j)
            for (int k = 0; k <= n; ++k)
                (res.mat[i][j] += a.mat[i][k] * b.mat[k][j]) %= mod;
    return res;
}
Mat pow(Mat a, int n, ll p)
{
    Mat res;
    for (int i = 0; i <= n; ++i)
        res.mat[i][i] = 1;
    while (p)
    {
        if (p & 1)
            res = mul(res, a, n);
        a = mul(a, a, n);
        p >>= 1;
    }
    return res;
}
char s[N];
void solve()
{
    io(n, m, mod);
    io(s);
    insert(s, m);
    getfail();
    Mat ans;
    for (int i = 0; i <= cnt; ++i)
    {
        if (f[i])
            continue;
        for (int j = 0; j < M; ++j)
        {
            if (f[trie[i][j]])
                continue;
            ans.mat[i][trie[i][j]] += 1;
        }
    }
    ans = pow(ans, cnt, n);
    ll tot = 0;
    for (int i = 0; i <= cnt; ++i)
        (tot += ans.mat[0][i]) %= mod;
    io(tot, '\n');
}

MAIN_FUNC