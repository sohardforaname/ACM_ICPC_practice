#include <bits/stdc++.h>
using namespace std;
int dp[20][2]; //��i��j�����
int a[20];
int dfs(int pos, int pre, bool lim, bool tag) //��һλ�����֣���һλ���֣����ޣ�6�ı��
{
    if (pos == -1) //�Ѿ�����ͷ��
        return 1;
    if (!lim && dp[pos][tag] != -1) //���仯������һ��Ҫ�ж��Ƿ��б߽磬�б߽�ʱ���㲻���������
        return dp[pos][tag];
    int res = lim ? a[pos] : 9; //���ñ߽�
    int ans = 0;
    for (int i = 0; i <= res; ++i)
    {
        if (i == 4 || (i == 2 && pre == 6))
            continue;
        ans += dfs(pos - 1, i, lim && i == a[pos], i == 6); //�б߽���i�����˱߽磬��һλҲ���б߽�
    }
    if (!lim)
        dp[pos][tag] = ans; //��¼
    return ans;
}
int solve(int num)
{
    memset(a, 0, sizeof(a));
    int pos = 0;
    while (num)
    {
        a[pos++] = num % 10;
        num /= 10;
    }
    return dfs(pos - 1, 0, true, 0); //�տ�ʼ��ʱ��һ���б߽�
}
int main()
{
    int n, m;
    while (cin >> n >> m && n + m)
    {
        memset(dp, -1, sizeof(dp));
        cout << solve(m) - solve(n - 1) << endl;
    }
    return 0;
}
