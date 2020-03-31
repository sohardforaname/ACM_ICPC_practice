#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>ans[300005];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int fir = 0, las = 0, a, n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a;
		ans[a].push_back(i);
		if (i == 0)
			fir = a;
		else if (i == n - 1)
			las = a;
	}
	int ans1 = 0, ans2 = 0;
	for (int i = 0; i <= n; ++i)
	{
		if (ans[i].size() == 0)
			continue;
		if (i != fir)
			ans1 = max(ans1, *(ans[i].end() - 1));
		if (i != las)
			ans2 = max(ans2, n - 1 - *ans[i].begin());
	}
	cout << max(ans1, ans2) << endl;
	return 0;
}