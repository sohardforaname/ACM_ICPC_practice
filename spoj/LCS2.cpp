#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const int M = 26;
char s[N];
struct SAM
{
    int nxt[N][M], link[N], maxl[N];
    int last, root, size, n;
    SAM() : last(1), size(1), root(1) {}
    void extend(int ch)
    {
        ++n;
        ch -= 'a';
        int cur = (++size), p;
        maxl[cur] = maxl[last] + 1;
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
    int c[N], rnk[N];
    void pre()
    {
        for (int i = 1; i <= size; ++i)
            ++c[maxl[i]];
        for (int i = 1; i <= n; ++i)
            c[i] += c[i - 1];
        for (int i = 1; i <= size; ++i)
            rnk[c[maxl[i]]--] = i;
    }
    int maxn[N], minn[N];
    int work()
    {
        pre();
        for (int i = 1; i <= size; ++i)
            minn[i] = maxl[i];
        while (~scanf("%s", s))
        {
            memset(maxn, 0, sizeof(maxn));
            int now = root, len = 0;
            for (int i = 0; s[i]; ++i)
            {
                int ch = s[i] - 'a';
                if (nxt[now][ch])
                    ++len;
                else
                {
                    while (now && !nxt[now][ch])
                        now = link[now];
                    if (!now)
                        len = 0;
                    else
                        len = maxl[now] + 1;
                }
                now = now ? nxt[now][ch] : root;
                maxn[now] = max(maxn[now], len);
            }
            for (int i = size; i; --i)
            {
                int x = rnk[i], fa = link[x];
                maxn[fa] = max(maxn[fa], maxn[x]);
            }
            for (int i = 1; i <= size; ++i)
                minn[i] = min(minn[i], maxn[i]);
        }
        int ans = 0;
        for (int i = 1; i <= size; ++i)
            ans = max(ans, minn[i]);
        return ans;
    }
};
SAM sam;
int main()
{
    scanf("%s", s);
    for (int i = 0; s[i]; ++i)
        sam.extend(s[i]);
    printf("%d\n", sam.work());
    return 0;
}