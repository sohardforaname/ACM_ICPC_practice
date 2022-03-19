#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 5;
const int M = 26;
struct SAM
{
    int nxt[N][M], link[N], maxl[N];
    int last, root, size;
    int sz[N];
    SAM() : last(1), root(1), size(1) {}
    void extend(int ch)
    {
        ch -= 'a';
        int cur = ++size, p;
        maxl[cur] = maxl[last] + 1;
        sz[size] = 1;
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
                link[q] = link[cur] = tmp;
            }
        }
        last = cur;
    }
    int c[N], id[N];
    void sort() //基数排序
    {
        for (int i = 1; i <= size; ++i)
            ++c[maxl[i]];
        for (int i = 1; i <= size; ++i)
            c[i] += c[i - 1];
        for (int i = 1; i <= size; ++i)
            id[c[maxl[i]]--] = i;
    }
    ll get_ans()
    {
        sort();
        sz[1] = 1;
        ll ans = 0;
        for (int i = size; i; --i)
        {
            int cur = id[i];
            ans += 1ll * sz[link[cur]] * sz[cur] * maxl[link[cur]];
            sz[link[cur]] += sz[cur];
        }
        return ans;
    }
};
SAM sam;
char s[N];
int main()
{
    scanf("%s", s);
    int len = strlen(s);
    for (int i = 0; i < len; ++i)
        sam.extend(s[i]);
    printf("%lld\n", 1ll * len * (len - 1) * (len + 1) / 2 - 2 * sam.get_ans());
    return 0;
}