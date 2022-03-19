#include <bits/stdc++.h>
using namespace std;
multiset<long long>work[100005];
long long num[100005];
vector<long long>a;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n, k, s;
	cin >> n >> s;
	for (int i = 0; i < n; ++i)
		cin >> num[i];
	for (int i = 0; i < n; ++i)
	{
		cin >> k;
 		work[num[i] - 1].insert(k);
	}
	bool flag = 0;
	int cnt = 0;
	for (int i = 0; i < s; ++i)
	{
		if (work[i].size() > 1)
		{
			flag = 1;
			++cnt;
			for (auto i : work[i])
				a.push_back(i);
			a.pop_back();
		}
		else if (work[i].size() == 1)
			++cnt;
	}
	if (!flag)
		cout << 0 << endl;
	else
	{
		long long ans = 0;
		sort(a.begin(), a.end());
		for (int i = 0; i < s - cnt; ++i)
			ans += a[i];
		cout << ans << endl;
	}
	return 0;
}