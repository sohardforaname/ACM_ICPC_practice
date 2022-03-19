#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
char s[N];
void solve()
{
    int n, a;
    scanf("%d", &n);
    memset(s, 'a', sizeof(s[0]) * 1e2);
    printf("%s\n", s);
    while (n--)
    {
        scanf("%d", &a);
        char ch;
        for (int i = 0; i < 26; ++i)
            if (s[a] != i + 'a')
            {
                ch = i + 'a';
                break;
            }
        for (int i = a; i < 1e2; ++i)
            s[i] = ch;
        printf("%s\n", s);
    }
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}