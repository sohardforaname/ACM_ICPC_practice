#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;
long long num[100005];
stack<int> s;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	while (cin >> n && n)
	{
		for (int i = 0; i < n; ++i)
			cin >> num[i];
		num[n] = 0;
		long long ans = 0;
		for (int i = 0; i <= n; ++i)
		{
			while (!s.empty() && num[s.top()] > num[i])
			{
				int tmp = s.top();
				s.pop();
				ans = max(ans, (s.empty() ? i : i - s.top() - 1) * num[tmp]);
			}
			s.push(i);
		}
		while (!s.empty())
			s.pop();
		cout << ans << endl;
	}
	return 0;
}