#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
deque<int> q1;
deque<pair<int, int>> q2;
char s[N];
void solve()
{
    q1.clear();
    q2.clear();
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);
    int cnt = 0;
    for (int i = 1; i <= n;)
    {
        int cur = i;
        while (cur <= n && s[i] == s[cur])
            ++cur;
        ++cnt;
        if (cur - i > 1)
            q2.push_back({cnt, cur - i});
        q1.push_back(cnt);
        i = cur;
    }
    int ans = 0;
    while (q1.size() > 1)
    {
        if (q2.size())
        {
            if (q2.front().second > 2)
                --q2.front().second;
            else
                q2.pop_front();
            if (q2.size() && q2.front().first == q1.front())
                q2.pop_front();
            q1.pop_front();
        }
        else
        {
            q1.pop_front();
            q1.pop_front();
        }
        ++ans;
    }
    if (q1.size())
        ++ans;
    printf("%d\n", ans);
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}