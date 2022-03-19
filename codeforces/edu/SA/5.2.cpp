#include <bits/stdc++.h>
using namespace std;
const int N = 400005;
struct SuffixArray
{
    int n, m;
    int tax[N], rank[N], tp[N], sa[N];
    int height[N];
    char ch[N << 1];
    void sort() //基数排序
    {
        for (int i = 0; i <= m; ++i)
            tax[i] = 0;
        for (int i = 1; i <= n; ++i)
            ++tax[rank[i]];
        for (int i = 1; i <= m; ++i)
            tax[i] += tax[i - 1];
        for (int i = n; i >= 1; --i)
            sa[tax[rank[tp[i]]]--] = tp[i];
    }
    bool cmp(int a, int b, int k)
    {
        return tp[a] == tp[b] && tp[a + k] == tp[b + k];
    }
    void get_sa()
    {
        n = strlen(ch + 1);
        for (int i = 1; i <= n; ++i)
            m = max(m, rank[i] = ch[i] - '0'), tp[i] = i;
        sort();
        for (int p = 0, j = 1; p < n; j <<= 1, m = p)
        {
            p = 0; //清空
            for (int i = 1; i <= j; ++i)
                tp[++p] = n - j + i;
            for (int i = 1; i <= n; ++i)
                if (sa[i] > j)
                    tp[++p] = sa[i] - j;
            sort();
            swap(rank, tp);
            rank[sa[1]] = p = 1;
            for (int i = 2; i <= n; ++i)
                rank[sa[i]] = cmp(sa[i], sa[i - 1], j) ? p : ++p;
        }
        get_height();
    }
    void get_height()
    {
        int k = 0;
        for (int i = 1; i <= n; ++i)
            rank[sa[i]] = i;
        for (int i = 1; i <= n; ++i)
        {
            if (rank[i] == 1)
                continue;
            if (k)
                --k;
            int j = sa[rank[i] - 1];
            while (j + k <= n && i + k <= n && ch[j + k] == ch[i + k])
                ++k;
            height[rank[i]] = k;
        }
    }
};
typedef long long ll;
SuffixArray sa;
int g[N];
int main()
{
    scanf("%s", sa.ch + 1);
    int len = strlen(sa.ch + 1);
    sa.ch[len + 1] = '?';
    scanf("%s", sa.ch + len + 2);
    sa.get_sa();
    int maxn = 0, pos = 0;
    for (int i = 1; i <= sa.n; ++i)
        if (sa.sa[i] > len + 1)
            g[i] = 1;
    for (int i = 2; i <= sa.n; ++i)
        if (g[i] ^ g[i - 1] && maxn < sa.height[i])
        {
            maxn = sa.height[i];
            pos = i - 1;
        }
    for (int i = 0; i < maxn; ++i)
        putchar(sa.ch[sa.sa[pos] + i]);
    putchar('\n');
    return 0;
}