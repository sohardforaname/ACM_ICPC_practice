#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
void solve()
{
    string s, t;
    cin >> s >> t;
    if (s == t)
        printf("same\n");
    else
    {
        for (auto &i : s)
            i = tolower(i);
        for (auto &i : t)
            i = tolower(i);
        if (s == t)
            printf("case-insensitive\n");
        else
            printf("different\n");
    }
}
int main()
{
    int T = 1;
    //scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}