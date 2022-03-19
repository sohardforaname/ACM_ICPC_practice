#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
int a[N], l[N << 5], r[N << 5];
int trie[N << 5][2];
int cnt;
void insert(int n, int pos)
{
    int root = 0;
    for (int i = 31; ~i; --i)
    {
        int val = (n >> i) & 1;
        if (!trie[root][val])
        {
            trie[root][val] = ++cnt;
            l[cnt] = pos;
            r[cnt] = pos;
        }
        l[root] = min(l[root], pos);
        r[root] = max(r[root], pos);
        root = trie[root][val];
    }
}

int query(int n, int root, int bit)
{
    int ans = 1 << (bit + 1);
    for (int i = bit; ~i; --i)
    {
        int val = (n >> i) & 1;
        if (trie[root][val])
            root = trie[root][val];
        else
        {
            ans |= 1 << i;
            root = trie[root][val ^ 1];
        }
    }
    return ans;
}

ll dfs(int root, int bit)
{
    if (bit == 0)
        return (trie[root][0] && trie[root][1])
                   ? a[l[trie[root][0]]] ^ a[r[trie[root][1]]]
                   : 0;
    ll res = 0;
    if (trie[root][0] && trie[root][1])
    {
        int minn = 1 << 30;
        for (int i = l[trie[root][0]]; i <= r[trie[root][0]]; ++i)
            minn = min(minn, query(a[i], trie[root][1], bit - 1));
        res += minn;
    }
    if (trie[root][0])
        res += dfs(trie[root][0], bit - 1);
    if (trie[root][1])
        res += dfs(trie[root][1], bit - 1);
    return res;
}

int main()
{
    int n;
    scanf("%d", &n);
    l[0] = 0x3f3f3f3f, r[0] = 0;
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i)
        insert(a[i], i);
    printf("%lld\n", dfs(0, 31));
    return 0;
}