#include <bits/stdc++.h>
using namespace std;
const int N = 1.2e6 + 5;
struct SAM
{
    map<int, int> nxt[N];
    int link[N], maxl[N];
    int last, size, root;
    SAM() : last(1), size(1), root(1) {}
    void extend(int val)
    {
        int cur = ++size, p;
        maxl[cur] = maxl[last] + 1;
        for (p = last; p && nxt[p].find(val) == nxt[p].end(); p = link[p])
            nxt[p][val] = cur;
        if (!p)
            link[cur] = root;
        else
        {
            int q = nxt[p][val];
            if (maxl[q] == maxl[p] + 1)
                link[cur] = q;
            else
            {
                int tmp = ++size;
                maxl[tmp] = maxl[p] + 1;
                for (auto i : nxt[q])
                    nxt[tmp].insert(i);
                link[tmp] = link[q];
                for (;; p = link[p])
                {
                    auto it = nxt[p].find(val);
                    if (it != nxt[p].end() && (*it).second == q)
                        nxt[p].erase(it), nxt[p][val] = tmp;
                    else
                        break;
                }
                link[cur] = link[q] = tmp;
            }
        }
        last = cur;
    }
    void get_ans(int n)
    {
        int now = 1;
        for (int i = 1; i <= n; ++i)
        {
            printf("%d ", (*nxt[now].begin()).first);
            now = (*nxt[now].begin()).second;
        }
        printf("\n");
    }
};
SAM sam;
int s[N];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &s[i]);
    for (int j = 1; j <= 2; ++j)
        for (int i = 1; i <= n; ++i)
            sam.extend(s[i]);
    sam.get_ans(n);
    return 0;
}