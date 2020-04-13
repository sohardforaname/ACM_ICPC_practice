#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
typedef long long ll;
void solve()
{
    int n, k;
    scanf("%d%d", &n, &k);
    printf("%d\n", (k - n % k) % k);
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}