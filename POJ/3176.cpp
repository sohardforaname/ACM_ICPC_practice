#include <iostream>
#include <algorithm>
using namespace std;
int num[355];
int dp[355];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j <= i; ++j)
			cin >> num[j];
		for (int j = i + 1; j > 0; --j)
			dp[j] = max(dp[j], dp[j - 1]) + num[j - 1];//����һ�㵽��һ��ʱ��ֻ���Ǵ����Ϸ������Ϸ�
		//ֻ����һ���йأ���ʹ��dp[i]��dp[i-1]������һ�㣬�Ӻ���ǰ���£���Ϊ����ǰ����dp[i-1]��������һ�е�ֵ
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i)
		ans = max(ans, dp[i]);//�����һ�еõ����ֵ
	cout << ans << endl;
	return  0;
}