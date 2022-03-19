#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 1e4 + 5;
int x[N], y[N];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &x[i], &y[i]);
    sort(x + 1, x + n + 1);
    sort(y + 1, y + n + 1);
    int sum = 0;
    for (int i = 1; i <= n; ++i)
        x[i] -= i;
    sort(x + 1, x + n + 1);
    for (int i = 1; i <= n; ++i)
        sum += abs(x[i] - x[(1 + n) >> 1]);
    for (int i = 1; i <= n; ++i)
        sum += abs(y[i] - y[(1 + n) >> 1]);
    printf("%d\n", sum);
    return 0;
}