#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e3 + 5;
void solve()
{
    int n;
    scanf("%d", &n);
    if (n % 2 == 0)
        printf("%d\n", (n / 2 + 1) * (n / 2 + 1));
    else
        printf("%d\n", 2 * (n / 2 + 1) * (n / 2 + 2));
}
int main()
{
    int t = 1;
    //scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}