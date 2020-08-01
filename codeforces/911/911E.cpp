#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
stack<int> s;
int a[N], b[N];
bool vis[N];
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= k; ++i)
        scanf("%d", &a[i]);
    int maxn = 0;
    for (int i = 1; i <= k; ++i)
    {
        s.push(a[i]);
        while (s.size() && s.top() - 1 == maxn)
            s.pop(), ++maxn;
    }
    int top = 0, pre = maxn;
    while (s.size())
    {
        int tmp = s.top();
        s.pop();
        if (pre > tmp)
            return printf("-1\n"), 0;
        for (int i = tmp - 1; i > pre; --i)
            b[++top] = i;
        maxn = tmp;
        pre = tmp;
    }
    int tmp = n;
    while (++maxn <= n)
        b[++top] = tmp--;
    for (int i = 1; i <= k; ++i)
        printf("%d ", a[i]);
    for (int i = 1; i <= n - k; ++i)
        printf("%d ", b[i]);
    printf("\n");
    return 0;
}