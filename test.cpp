#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
char s[N];
pair<int, int> p1[N], p2[N];
int n, cnt;
bool check(int k)
{
    if (cnt < 2 * k)
        return 0;
    if (k == 0)
        return 1;
    return p1[k].second < p2[k].first;
}
int main()
{
    while (~scanf("%d%s", &n, s + 1))
    {
        cnt = 0;
        queue<int> q1, q2;
        for (int i = 1; i <= n; ++i)
        {
            if (s[i] == '2')
                q1.push(i);
            else if (s[i] == '0' && q1.size())
                p1[++cnt] = {q1.front(), i}, q1.pop();
        }
        cnt = 0;
        for (int i = n; i; --i)
        {
            if (s[i] == '0')
                q2.push(i);
            else if (s[i] == '2' && q2.size())
                p2[++cnt] = {i, q2.front()}, q2.pop();
        }
        int l = 0, r = cnt / 2, ans = 0;
        while (l <= r)
        {
            int m = (l + r) >> 1;
            if (check(m))
            {
                l = m + 1;
                ans = m;
            }
            else
                r = m - 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}