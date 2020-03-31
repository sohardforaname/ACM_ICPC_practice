#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
int num[100005];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, e;
	cin >> n >> e;
	for (int i = 0; i < n; ++i)
		cin >> num[i];
	int ans = 1, cnt = 1;
	for (int i = 1; i < n; ++i)
	{
		if (num[i] != num[i - 1])
			++cnt;
		else
			cnt = 1;
		ans = max(ans, cnt);
	}
	cout << ans << endl;
	return 0;
}