#include <bits/stdc++.h>
using namespace std;
stack<int> s;
long long a[100005];
int main()
{
    int n;
    while (~scanf("%d", &n) && n)
    {
        for (int i = 0; i < n; ++i)
            scanf("%lld", &a[i]);
        while (!s.empty())
            s.pop();
        long long ans = 0;
        a[n] = 0;
        for (int i = 0; i <= n; ++i)
        {
            while (!s.empty() && a[s.top()] > a[i])
            {
                int tmp = s.top();
                s.pop();
                ans = max(ans, (s.empty() ? i : i - s.top() - 1) * a[tmp]);
            }
            s.push(i);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
