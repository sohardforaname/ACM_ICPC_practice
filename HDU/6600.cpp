#include <bits/stdc++.h>
using namespace std;
const int mod = 1000003;
long long solve(int x)
{
    if (x >= mod)
        return 0;
    long long ans = 1;
    for (int i = 1; i <= x; ++i)
        ans = (ans * i) % mod;
    return ans;
}
int main()
{
    int n;
    while (cin >> n)
        cout << solve(n) << endl;
    return 0;
}
