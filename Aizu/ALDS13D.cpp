#include <bits/stdc++.h>
using namespace std;
vector<int> v;
stack<int> s;
stack<pair<int, int>> ps;
string str;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> str;
	int sum = 0, cnt = 0;
	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] == '\\')
			s.push(i);
		else if (str[i] == '/' && s.size())
		{
			int j = s.top();
			s.pop();
			cnt = i - j;
			sum += cnt;
			while (ps.size() && ps.top().first > j) //如果水位上涨，左边界一定变小
			{
				cnt += ps.top().second;
				ps.pop();
			}
			ps.push(make_pair(j, cnt));
		}
	}
	cout << sum << '\n'
		 << ps.size();
	while (ps.size())
	{
		v.push_back(ps.top().second);
		ps.pop();
	}
	for (int i = v.size() - 1; ~i; --i)
		cout << " " << v[i];
	cout << '\n';
	return 0;
}