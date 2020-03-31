#include <bits/stdc++.h>
using namespace std;
int l[100005], s[100005], v[100005];
long long sum[100005];
int main()
{
    int n;
    while (cin >> n)
    {
        for (int i = 0; i < n + 1; ++i)
            scanf("%d", &l[i]);
        for (int i = 0; i < n + 1; ++i)
            scanf("%d", &s[i]);
        for (int i = 0; i < n + 1; ++i)
            scanf("%d", &v[i]);
        double maxx = 0;
        sum[0] = 0;
        for (int i = 1; i < n + 1; ++i)
            sum[i] = sum[i - 1] + l[i];
        for (int i = 0; i < n + 1; ++i)
            maxx = max(maxx, double(s[i] + sum[i]) / double(v[i]));
        printf("%.10f\n", maxx);
    }
    return 0;
}
