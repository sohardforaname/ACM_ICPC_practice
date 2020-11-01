#include <bits/stdc++.h>
using namespace std;
const int N = 400005;
int c[20][N];
int cyc;
struct SuffixArray
{
    int n, m;
    int tax[N], rank[N], tp[N], sa[N];
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
            m = max(m, rank[i] = ch[i] - ' '), tp[i] = i;
        sort();
        memcpy(&c[cyc++][1], rank + 1, sizeof(int) * n);
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
            memcpy(&c[cyc++][1], rank + 1, sizeof(int) * n);
        }
        while ((1 << cyc) < n)
            memcpy(&c[cyc++][1], rank + 1, sizeof(int) * n);
    }
};
SuffixArray sa;
struct node
{
    int l, r;
};
bool cmp(const node &a, const node &b)
{
    int lena = a.r - a.l + 1, lenb = b.r - b.l + 1;
    int len = min(lena, lenb), llen = log2(len);
    pair<int, int> pa = {c[llen][a.l], c[llen][a.l + len - (1 << llen)]},
                   pb = {c[llen][b.l], c[llen][b.l + len - (1 << llen)]};
    return pa == pb ? (lena == lenb ? a.l < b.l : lena < lenb) : pa < pb;
}
node q[N];
int main()
{
    scanf("%s", sa.ch + 1);
    sa.get_sa();

    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &q[i].l, &q[i].r);
    sort(q + 1, q + n + 1, cmp);
    for (int i = 1; i <= n; ++i)
        printf("%d %d\n", q[i].l, q[i].r);
    return 0;
}
