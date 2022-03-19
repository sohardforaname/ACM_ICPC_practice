#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
typedef long long ll;
pair<double, double> p[N];
#define equ(a, b) (fabs((a) - (b)) < 1e-8)
bool cmp(const pair<double, double> &a, const pair<double, double> &b)
{
    return equ(a.second, b.second) ? a.first < b.first : a.second < b.second;
}
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        p[i] = {a - sqrt(1.0 * k * k - 1.0 * b * b),
                a + sqrt(1.0 * k * k - 1.0 * b * b)};
    }
    sort(p + 1, p + n + 1, cmp);
    double tmp = p[1].second;
    int cnt = 1;
    for (int i = 2; i <= n; ++i)
        if (p[i].first > (ll)tmp)
            ++cnt, tmp = p[i].second;
    printf("%d\n", cnt);
    return 0;
}