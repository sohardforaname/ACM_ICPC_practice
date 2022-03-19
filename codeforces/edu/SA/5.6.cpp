#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
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
        SAIS(s, t, tmp, n, 300);
        --n;
        for (int i = 1; i <= n; ++i)
            Rank[SA[i] = SA[i + 1]] = i;
        for (int i = 1, L = 0, j; i <= n; Height[Rank[i++]] = L)
            for (j = SA[~(-Rank[i])], L -= L > 0; i + L <= n && j + L <= n && s[i + L] == s[j + L]; ++L)
                ;
    }
};
SuffixArray sa;
int st[N][20];
int query(int l, int r)
{
    int k = log(r - l + 1);
    return min(st[l][k], st[r - (1 << k) + 1][k]);
}
int main()
{
    scanf("%s", sa.str + 1);
    sa.get_sa();
    for (int i = 1; i <= sa.n; ++i)
        st[i][0] = sa.Height[i];
    for (int j = 1; (1 << j) <= sa.n; ++j)
        for (int i = 1; i + (1 << j) - 1 <= sa.n; ++i)
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    int tms = 1;
    for (int i = 1; i <= sa.n; ++i)
        for (int j = 1; j <= sa.n; j += i)
        {
            int tmp = query(j, j + i);
            int t = tmp / i + 1;
            int v = j - (i - tmp % i);
            if (v >= 0 && tmp % i && query(v, v + i) >= tmp)
                ++t;
            tms = max(tms, t);
        }
    printf("%d\n", tms);
}