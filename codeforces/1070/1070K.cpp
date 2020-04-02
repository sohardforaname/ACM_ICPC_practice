#include <iostream>
#include <string>
#include <vector>
using namespace std;
int num[100005];
long long sum;
vector<int>ans;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
	{
		cin >> num[i];
		sum += num[i];
	}
	if (sum%k)
	{
		cout << "No" << endl;
		return 0;
	}
	sum /= k;
	long long tmp = 0; int pos = 0;
	for (int i = 0; i < n; ++i)
	{
		if (tmp < sum)
			tmp += num[i], ++pos;
		else if (tmp == sum)
		{
			ans.push_back(pos);
			tmp = num[i];
			pos = 1;
		}
		else
			tmp = num[i], pos = 1;
	}
	ans.push_back(pos);
	if (ans.size() < k)
		cout << "No" << endl;
	else
	{
		cout << "Yes" << endl;
		for (auto i : ans)
			cout << i << " ";
		cout << endl;
	}
	return 0;
}