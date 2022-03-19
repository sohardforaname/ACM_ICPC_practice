#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<long long> num;
void dfs(int dep, long long n)
{
	if (dep == 12)
		return;
	num.push_back(n);
	dfs(dep + 1, n * 10 + 4);
	dfs(dep + 1, n * 10 + 7);
	return;
}
int main()
{
	dfs(1, 4);
	dfs(1, 7);
	sort(num.begin(), num.end());
	//for(int i=0;i<num.size();++i)
	//	cout<<num[i]<<endl;
	long long n, m, pos1 = 0, pos2 = 0;
	cin >> n >> m;
	long long ans = 0;
	for (int i = 0; i < num.size(); ++i)
	{
		if (n > num[i])
			++pos1;
		else
			break;
	}
	for (int i = 0; i < num.size(); ++i)
	{
		if (m >= num[i])
			++pos2;
		else
			break;
	}
	if (pos1 == pos2)
		cout << (m - n + 1) * num[pos1] << endl;
	if (pos2 != pos1)
	{
		ans += (num[pos1] + 1 - n) * num[pos1];
		//cout<<ans<<endl;
		for (int i = pos1; i < pos2 - 1; ++i)
		{
			ans += (num[i + 1] - num[i]) * num[i + 1];
		}
		ans += (m - num[pos2 - 1]) * num[pos2];
		cout << ans << endl;
	}
	return 0;
}