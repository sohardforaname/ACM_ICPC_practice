#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
void solve()
{
    int n;
    scanf("%d", &n);
    while (n % 5 == 0)
        n /= 5;
    while (n % 2 == 0)
        n /= 2;
    if (n == 1)
        printf("No\n");
    else
        printf("Yes\n");
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}