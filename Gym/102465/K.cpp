#include <bits/stdc++.h>
using namespace std;
const int N = 7e2 + 5;
int fail[N];
void getfail(char *s, int len)
{
    fail[0] = -1;
    int j = -1, k = 0;
    while (k < len)
    {
        if (j == -1 || s[j] == s[k])
            fail[++k] = ++j;
        else
            j = fail[j];
    }
}
char s[N];
int solve(char *s, int len)
{
    if (len == 0)
        return 0;
    if (len == 1)
        return 1;
    getfail(s, len);
    int l = 1, tms = 1;
    for (int i = 1; i <= len; ++i)
        if (i % (i - fail[i]) == 0 && i / (i - fail[i]) > 1)
            l = i - fail[i], tms = i / (i - fail[i]);
    return solve(s, l) + solve(s + l * tms, len - l * tms);
}
int main()
{
    int n;
    scanf("%d%s", &n, s);
    printf("%d\n", solve(s, n));
    return 0;
}