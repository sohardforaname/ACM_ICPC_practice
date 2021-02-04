#include <bits/stdc++.h>
using namespace std;
vector<int> v;
const int N = 1e5 + 5;
char s[N];
int sum[N];
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int a, b;
        scanf("%d%d%s", &a, &b, s + 1);
        int len = strlen(s + 1);
        int cnt = 1;
        for (int i = 2; i <= len + 1; ++i)
        {
            if (s[i] == s[i - 1])
                ++cnt;
            else
                v.push_back(cnt), cnt = 1;
        }
        int l = 0, r = v.size() - 1;
        if (s[1] == '0')
            ++l;
        if (s[len] == '0')
            --r;
        int top = 0;
        for (int i = l + 1; i <= r; i += 2)
            sum[++top] = v[i];
        sort(sum + 1, sum + top + 1);
        for (int i = 1; i <= top; ++i)
            sum[i] += sum[i - 1];
        int minn = INT_MAX;
        for (int i = 0; i <= top; ++i)
            minn = min(minn, ((r - l) / 2 + 1 - i) * a + sum[i] * b);
        printf("%d\n", minn);
        v.clear();
    }
    return 0;
}