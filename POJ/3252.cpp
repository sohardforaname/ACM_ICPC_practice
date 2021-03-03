#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
long long dp[35][100], a[35];
long long dfs(int pos, int sta, bool lead, int lim)
{
    if (pos == -1)
        return sta <= 32;
    if (!lim && !lead && dp[pos][sta] != -1) //��ǰ��0���ͻ�Ӱ��ʵ�ʵ�0��1���ж�
        return dp[pos][sta];
    int res = lim ? a[pos] : 1;
    long long ans = 0;
    for (int i = 0; i <= res; ++i) {
        if (lead && i == 0) //ǰ��0���ж�0��Ӱ�죬��ǰ��0�ұ�λ��0ʱ��֤����û�е���������λ��һ��i��1���ͻ����else
            ans += dfs(pos - 1, sta, lead, lim && i == a[pos]);
        else //����iΪ1��˵����������λ��ʼ�ˣ����涼����Ϊû��ǰ��0
            ans += dfs(pos - 1, sta + (i ? 1 : -1), lead && i == 0, lim && i == a[pos]);
    }
    if (!lim && !lead)
        dp[pos][sta] = ans;
    return ans;
}
long long solve(int x)
{
    int pos = 0;
    while (x) {
        a[pos++] = x % 2;
        x >>= 1;
    }
    return dfs(pos - 1, 32, true, true);
}
int main()
{
    memset(dp, -1, sizeof(dp));
    int l, r;
    cin >> l >> r;
    cout << solve(r) - solve(l - 1);
    return 0;
}
