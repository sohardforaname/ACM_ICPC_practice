#include <bits/stdc++.h>
using namespace std;
const int N = 400005;
struct SuffixArray
{
    int s[(N << 1) + 5], SA[N + 5], Rank[N + 5], Height[N + 5];
    int c[N + 5], p[N + 5], tmp[N + 5], n, m;
    bool t[(N << 1) + 5];
    char str[N + 5];

#define Ar(x, a) SA[p[s[x]] a] = x
#define IS(s1)                                             \
    memset(SA + 1, 0, n << 2);                             \
    memset(c + 1, 0, m << 2);                              \
    for (int i = 1; i <= n; ++i)                           \
        ++c[s[i]];                                         \
    partial_sum(c + 1, c + m + 1, c + 1);                  \
    memcpy(p + 1, c + 1, m << 2);                          \
    for (int i = n1; i; --i)                               \
        Ar(s1[i], --);                                     \
    transform(c, c + m, p + 1, [](int a) { return ++a; }); \
    for (int i = 1; i <= n; ++i)                           \
        SA[i] > 1 && t[SA[i] - 1] ? Ar(SA[i] - 1, ++) : 0; \
    memcpy(p + 1, c + 1, m << 2);                          \
    for (int i = n; i; --i)                                \
        SA[i] > 1 && !t[SA[i] - 1] ? Ar(SA[i] - 1, --) : 0;

    void SAIS(int s[], bool t[], int tmp[], int n, int m)
    {
        int n1 = 0, m1 = Rank[1] = 0, *s1 = s + n;
        t[n] = 0;
        for (int i = n - 1; i; --i)
            t[i] = s[i] ^ s[i + 1] ? s[i] > s[i + 1] : t[i + 1];
        for (int i = 2; i <= n; ++i)
            Rank[i] = t[i - 1] && !t[i] ? tmp[++n1] = i, n1 : 0;
        IS(tmp);
        for (int i = 1, x, y = 0; i <= n; ++i)
            if (x = Rank[SA[i]])
            {
                if (m1 <= 1 || tmp[x + 1] - tmp[x] != tmp[y + 1] - tmp[y])
                    ++m1;
                else
                    for (int a = tmp[x], b = tmp[y]; a <= tmp[x + 1]; ++a, ++b)
                        if ((s[a] << 1 | t[a]) ^ (s[b] << 1 | t[b]))
                        {
                            ++m1;
                            break;
                        }
                s1[y = x] = m1;
            }
        if (m1 < n1)
            SAIS(s1, t + n, tmp + n1, n1, m1);
        else
            for (int i = 1; i <= n1; ++i)
                SA[s1[i]] = i;
        for (int i = 1; i <= n1; ++i)
            s1[i] = tmp[SA[i]];
        IS(s1);
    }
    void get_sa()
    {
        n = strlen(str + 1);
        for (int i = 1; i <= n; ++i)
            s[i] = str[i] - 'a' + 2;
        s[++n] = 1;
        SAIS(s, t, tmp, n, 27);
        --n;
        for (int i = 1; i <= n; ++i)
            Rank[SA[i] = SA[i + 1]] = i;
        for (int i = 1, L = 0, j; i <= n; Height[Rank[i++]] = L)
            for (j = SA[~(-Rank[i])], L -= L > 0; i + L <= n && j + L <= n && s[i + L] == s[j + L]; ++L)
                ;
    }
};
SuffixArray sa;
int s[N], l[N], r[N];
int main()
{
    scanf("%s", sa.str + 1);
    sa.get_sa();
    int top = 0;
    sa.Height[0] = sa.Height[sa.n + 1] = -1;
    s[top++] = 0;
    for (int i = 1; i <= sa.n; ++i)
    {
        while (sa.Height[s[top - 1]] >= sa.Height[i])
            --top;
        l[i] = s[top - 1] + 1;
        s[top++] = i;
    }
    top = 0;
    s[top++] = sa.n + 1;
    for (int i = sa.n; i; --i)
    {
        while (sa.Height[s[top - 1]] > sa.Height[i])
            --top;
        r[i] = s[top - 1] - 1;
        s[top++] = i;
    }
    typedef long long ll;
    ll ans = 0;
    for (int i = 1; i <= sa.n; ++i)
        ans += 1ll * (i - l[i] + 1) * (r[i] - i + 1) * sa.Height[i];
    ans += sa.n * (sa.n + 1ll) / 2;
    printf("%lld\n", ans);
    return 0;
}