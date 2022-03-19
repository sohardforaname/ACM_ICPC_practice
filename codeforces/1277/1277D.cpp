#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
struct String
{
	string str;
	bool rev;
};
String str[N];
vector<int>vec[4];
unordered_map<string, int>mp;
void solve()
{
	mp.clear();
	for (int i = 0; i < 4; ++i)
		vec[i].clear();
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> str[i].str;
		++mp[str[i].str];
	}
	string tmp;
	for (int i = 1; i <= n; ++i)
	{
		reverse(str[i].str.begin(), str[i].str.end());
		tmp = str[i].str;
		reverse(str[i].str.begin(), str[i].str.end());
		if (mp[tmp])
			str[i].rev = 0;
		else
			str[i].rev = 1;
	}
	for (int i = 1; i <= n; ++i)
	{
		int a = str[i].str[0] - '0', b = str[i].str[str[i].str.size() - 1] - '0';
		if (a == 0 && b == 0)
			vec[0].push_back(i);
		else if (a == 1 && b == 1)
			vec[1].push_back(i);
		else if (a == 0 && b == 1)
			vec[2].push_back(i);
		else
			vec[3].push_back(i);
	}
	if (vec[0].size() && vec[1].size() && !(vec[2].size() || vec[3].size()))
	{
		printf("-1\n");
		return;
	}
	int del = abs((int)vec[2].size() - (int)vec[3].size());
	if (del == 0)
	{
		printf("0\n");
		return;
	}
	int cnt = 0;
	if (vec[2].size() < vec[3].size())
	{
		printf("%d\n", del / 2);
		for (int i = 0; i < vec[3].size() && cnt < del / 2; ++i)
			if (str[vec[3][i]].rev)
				printf("%d ", vec[3][i]), ++cnt;
		printf("\n");
	}
	else
	{
		printf("%d\n", del / 2);
		for (int i = 0; i < vec[2].size() && cnt < del / 2; ++i)
			if (str[vec[2][i]].rev)
				printf("%d ", vec[2][i]), ++cnt;
		printf("\n");
	}
	return;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}