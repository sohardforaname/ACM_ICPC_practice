#include <bits/stdc++.h>
using namespace std;
priority_queue<int> q;
void solve()
{
    int n;
    scanf("%d", &n);
    if (n == 2)
        return void(printf("2\n1 2\n"));
    for (int i = 1; i <= n; ++i)
        if (i != n && i != n - 2)
            q.push(i);
    printf("2\n%d %d\n", n - 2, n);
    q.push(n - 1);
    while (q.size() > 1)
    {
        int a = q.top();
        q.pop();
        int b = q.top();
        q.pop();
        printf("%d %d\n", b, a);
        q.push((a + b) / 2);
    }
    q.pop();
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}