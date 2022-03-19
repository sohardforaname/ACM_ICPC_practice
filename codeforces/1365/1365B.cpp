#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N];
vector<int> v;
void solve()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    v.clear();
    v.push_back(a[1]);
    for (int i = 2; i < n; ++i)
    {
        if (a[i] > a[i - 1] && a[i] > a[i + 1])
            v.push_back(a[i]);
        else if (a[i] < a[i - 1] && a[i] < a[i + 1])
            v.push_back(a[i]);
    }
    v.push_back(a[n]);
    printf("%d\n", (int)v.size());
    for (auto &i : v)
        printf("%d ", i);
    printf("\n");
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}