#include <bits/stdc++.h>
using namespace std;
const int N = 300005;
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
SuffixArray sa;
char s[N];
int main()
{
    //scanf("%d",&sa.n);
    scanf("%s", sa.ch + 1);
    int len = strlen(sa.ch + 1);
    sa.get_sa();
    int q;
    scanf("%d", &q);
    while (q--)
    {
        scanf("%s", s + 1);
        int ql = strlen(s + 1);
        int l = 1, r = len, ans = -1;
        while (l <= r)
        {
            int m = (l + r) >> 1, tag = memcmp(sa.ch + sa.sa[m], s + 1, ql);
            if (tag < 0)
                l = m + 1;
            else if (tag > 0)
                r = m - 1;
            else
            {
                ans = m;
                break;
            }
        }
        if (ans != -1)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
