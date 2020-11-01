#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
char s[N];
int a[N], c[N];
int lowbit(int x)
{
    return x & (-x);
}
void update(int pos, int n, int val)
{
    for (; pos <= n; pos += lowbit(pos))
        c[pos] += val;
}
int query(int pos)
{
    int ans = 0;
    for (; pos; pos -= lowbit(pos))
        ans += c[pos];
    return ans;
}
int query(int l, int r)
{
    return query(r) - query(l - 1);
}
typedef long long ll;
deque<int> q[26];
int main()
{
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);
    reverse(s + 1, s + n + 1);
    for (int i = 1; i <= n; ++i)
        q[s[i] - 'a'].push_back(i);
    reverse(s + 1, s + n + 1);
    for (int i = 1; i <= n; ++i)
        a[i] = q[s[i] - 'a'].front(), q[s[i] - 'a'].pop_front();
    ll ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        ans += query(a[i] + 1, n);
        update(a[i], n, 1);
    }
    printf("%lld\n", ans);
    return 0;
}