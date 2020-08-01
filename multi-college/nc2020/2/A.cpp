#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
const int N = 1e5 + 5;
const int M = 1e6 + 5;
typedef long long ll;
string str[N];
int nxt[M];
ll hmod[2] = {998244353, 1000000007}, base[2] = {131, 37};
ll hs[2][M], f[2][M];
ll vis[M];
struct p_hash
{
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2> &p) const
    {
        return hash<T1>{}(p.first) ^ hash<T2>{}(p.second);
    }
};
unordered_map<pair<ll, ll>, ll, p_hash> mp;
void init()
{
    f[0][0] = f[1][0] = 1;
    for (int i = 0; i <= 1; ++i)
        for (int j = 1; j < M; ++j)
            f[i][j] = f[i][j - 1] * base[i] % hmod[i];
}
ll get_hash(int l, int r, int j)
{
    return (hs[j][r] - hs[j][l - 1] * f[j][r - l + 1] % hmod[j] + hmod[j]) % hmod[j];
}
void get_next(const string &str)
{
    nxt[0] = -1;
    int j = -1, k = 0;
    while (k < str.size())
    {
        if (j == -1 || str[j] == str[k])
            nxt[++k] = ++j;
        else
            j = nxt[j];
    }
}
const ll mod = 998244353;
int main()
{
    init();
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> str[i];
    for (int i = 1; i <= n; ++i)
    {
        pair<ll, ll> tmp;
        int len = str[i].size();
        for (int j = 0; j <= 1; ++j)
            for (int k = 0; k < len; ++k)
                hs[j][k + 1] = (hs[j][k] * base[j] % hmod[j] + str[i][k] - 'a' + 1) % hmod[j];
        for (int j = 1; j <= len; ++j)
        {
            tmp.first = get_hash(j, len, 0);
            tmp.second = get_hash(j, len, 1);
            ++mp[tmp];
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        get_next(str[i]);
        int len = str[i].size();
        memset(vis, 0, sizeof(vis[0]) * (str[i].size() + 1));
        for (int j = 0; j <= 1; ++j)
            for (int k = 0; k < len; ++k)
                hs[j][k + 1] = (hs[j][k] * base[j] % hmod[j] + str[i][k] - 'a' + 1) % hmod[j];
        pair<ll, ll> tmp;
        for (int j = len; j; --j)
        {
            tmp.first = get_hash(1, j, 0);
            tmp.second = get_hash(1, j, 1);
            ans = (ans + (mp[tmp] - vis[j] + mod) % mod * j % mod * j % mod) % mod;
            int tnxt = nxt[j];
            vis[tnxt] = (vis[tnxt] + mp[tmp]) % mod;
        }
    }
    cout << ans << endl;
    return 0;
}