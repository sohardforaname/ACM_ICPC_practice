#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 1e5 + 5;
typedef long long ll;
int a[N];
int n;
bool check(int m) //difference bigger than m or equal to m
{
    ll sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        int pos = lower_bound(a + 1, a + n + 1, a[i] + m) - a;
        sum += n - pos + 1;
    }
    return sum > n * (n - 1) / 4;
}
int main()
{
    while (~scanf("%d", &n))
    {
        for (int i = 1; i <= n; ++i)
            scanf("%d", &a[i]);
        sort(a + 1, a + n + 1);
        int l = 0, r = 1e9 + 5;
        while (l < r)
        {
            int m = (l + r) >> 1;
            if (check(m))
                l = m + 1;
            else
                r = m;
        }
        printf("%d\n", l - 1);
    }
    return 0;
}