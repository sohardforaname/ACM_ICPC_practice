#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
const int M = 26;
typedef long long ll;
struct SAM
{
    int nxt[N][M], link[N], maxl[N];
    int last, size, root;
    int sz[N];
    SAM() : last(1), size(1), root(1) {}
    void extend(int ch)
    {
        ch -= 'a';
        int cur = ++size, p;
        maxl[cur] = maxl[last] + 1;
        sz[cur] = 1;
        for (p = last; p && !nxt[p][ch]; p = link[p])
            nxt[p][ch] = cur;
        if (!p)
            link[cur] = root;
        else
        {
            int q = nxt[p][ch];
            if (maxl[q] == maxl[p] + 1)
                link[cur] = q;
            else
            {
                int tmp = ++size;
                maxl[tmp] = maxl[p] + 1;
                for (int i = 0; i < M; ++i)
                    nxt[tmp][i] = nxt[q][i];
                link[tmp] = link[q];
                for (; nxt[p][ch] == q; p = link[p])
                    nxt[p][ch] = tmp;
                link[cur] = link[q] = tmp;
            }
        }
        last = cur;
    }
    int c[N], id[N];
    void pre()
    {
        for (int i = 1; i <= size; ++i)
            ++c[maxl[i]];
        for (int i = 1; i <= size; ++i)
            c[i] += c[i - 1];
        for (int i = 1; i <= size; ++i)
            id[c[maxl[i]]--] = i;
    }
    ll sum[N];
    void get_str(int t)
    {
        for (int i = size; i; --i)
            sz[link[id[i]]] += sz[id[i]];
        for (int i = 1; i <= size; ++i)
        {
            if (t == 0)
                sum[i] = sz[i] = 1;
            else
                sum[i] = sz[i];
        }
        sz[1] = sum[1] = 0;
        for (int i = size; i; --i)
            for (int j = 0; j < M; ++j)
                if (nxt[id[i]][j])
                    sum[id[i]] += sum[nxt[id[i]][j]];
    }
    void get_ans(int k)
    {
        if (sum[1] < k)
        {
            printf("-1\n");
            return;
        }
        int now = root;
        while (k > 0)
        {
            k -= sz[now];
            if (k <= 0)
                break;
            int p = 0;
            while (k > sum[nxt[now][p]])
                k -= sum[nxt[now][p]], ++p;
            now = nxt[now][p];
            putchar(p + 'a');
        }
        putchar('\n');
    }
};
SAM sam;
char s[N];
int main()
{
    int t, k;
    scanf("%s%d%d", s, &t, &k);
    for (int i = 0; s[i]; ++i)
        sam.extend(s[i]);
    sam.pre();
    sam.get_str(t);
    sam.get_ans(k);
    return 0;
}