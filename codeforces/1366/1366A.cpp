#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
typedef long long ll;
typedef pair<int, int> pii;
void solve()
{
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d\n", min((a + b) / 3, min(a, b)));
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}