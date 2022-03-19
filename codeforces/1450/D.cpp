#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
int l[N], r[N];
int s[N], a[N], cnt[N];
bool vis[N];
char str[N];
vector<int> v[N];
set<int> ss;
void solve()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        vis[i] = 0;
        str[i] = '0';
        v[i].clear();
        cnt[i] = 0;
    }
    ss.clear();
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]), vis[a[i]] = 1;
    int top = 0;
    for (int i = 1; i <= n; ++i)
    {
        while (top && a[i] < a[s[top - 1]])
            r[s[--top]] = i - 1;
        s[top++] = i;
    }
    while (top)
        r[s[--top]] = n;
    for (int i = n; i; --i)
    {
        while (top && a[i] < a[s[top - 1]])
            l[s[--top]] = i + 1;
        s[top++] = i;
    }
    while (top)
        l[s[--top]] = 1;
    for (int i = 1; i <= n; ++i)
        v[r[i] - l[i] + 1].push_back(a[i]);
    for (int i = n; i; --i)
    {
        if (!vis[n - i + 1])
            break;
        for (auto num : v[i])
            ss.insert(num);
        if (ss.size() == n - i + 1)
            str[i] = '1';
    }
    for (int i = 1; i <= n + 1; ++i)
        printf("%c", i <= n ? str[i] : '\n');
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}