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
			dp[j] = max(dp[j], dp[j - 1]) + num[j - 1];//从上一层到下一层时，只能是从正上方和左上方
		//只与上一层有关，故使用dp[i]和dp[i-1]更新下一层，从后向前更新，因为若从前往后，dp[i-1]将不是上一行的值
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i)
		ans = max(ans, dp[i]);//在最后一行得到最大值
	cout << ans << endl;
	return  0;
}