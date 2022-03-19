#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<int, int> mp;
char s[10][16] = {
    "111101101101111",
    "010110010010111",
    "111001111100111",
    "111001111001111",
    "101101111001001",
    "111100111001111",
    "111100111101111",
    "111001001001001",
    "111101111101111",
    "111101111001111"};
void init()
{
    for (int i = 0; i < 10; ++i)
    {
        int res = 0;
        for (int j = 0; j < 15; ++j)
            if (s[i][j] - '0')
                res += 1 << j;
        mp[res] = i;
    }
}
char ch[10][250];
int get_num(int x)
{
    int res = 0;
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 3; ++j)
            if (ch[i + 1][j + x] == '#')
                res += 1 << (i * 3 + j);
    return mp[res];
}
void solve()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= 5; ++i)
        scanf("%s", &ch[i][1]);
    for (int i = 1; i <= n; ++i)
        printf("%d", get_num(i * 4 - 2));
    printf("\n");
}
int main()
{
    init();
    int T = 1;
    //scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}