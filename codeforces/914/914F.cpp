#include <iostream>
#include <string>
#include <bitset>
#include <algorithm>
//不会bitset加速
using namespace std;
bitset<100005>ans[26];
bitset<100005>k;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string a;
	for (int i = 0; i < 26; ++i)
		ans[i].set();
	for (int i = 0; i < a.size(); ++i)
		ans[a[i] - 'a'][i] = 1;
	int n;
	cin >> n;
	while (n--)
	{
		int m, s, t;
		char ch; 
		string b;
		cin >> m;
		if (m == 1)
		{
			cin >> s >> ch;
			ans[a[s] - 'a'][s - 1] = 0;
			ans[(a[s] = ch) - 'a'][s - 1] = 1;
		}
		else
		{
			cin >> s >> t >> b;
			for (int i = 0; i < b.size(); ++i)
				k &= (ans[b[i] - 'a'] >> j);
			int left = (k >> s).count(), right = (k >> (t - b.size() + 2)).count();//ans右移去掉匹配部分前面，去掉匹配部分的后面，
			//+2是为了字符串的计数闭区间+1同时+1为了字符串从1匹配变成从0匹配。
			cout << max(0, left - right) << endl;
		}
	}
	return 0;
}
