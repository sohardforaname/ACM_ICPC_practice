#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5, M = 26;
struct SAM
{
    int nxt[N][M], link[N], maxl[N];
    int last, size, root;
    SAM() : last(1), size(1), root(1) {}
    void extend(int ch)
    {
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
    int lcs(char *s)
    {
        int ans = 0, now = root, len = 0;
        for (int i = 0; s[i]; ++i)
        {
            int ch = s[i] - 'a';
            if (nxt[now][ch])
                now = nxt[now][ch], ++len;
            else
            {
                while (now && !nxt[now][ch])
                    now = link[now];
                if (!now)
                {
                    len = 0;
                    now = root;
                }
                else
                {
                    len = maxl[now] + 1;
                    now = nxt[now][ch];
                }
            }
            ans = max(ans, len);
        }
        return ans;
    }
};
SAM sam;
char s1[N], s2[N];
int main()
{
    scanf("%s%s", s1, s2);
    for (int i = 0; s1[i]; ++i)
        sam.extend(s1[i]);
    printf("%d\n", sam.lcs(s2));
    return 0;
}