#include <bits/stdc++.h>
#pragma GCC optimize(3)
using namespace std;
map<string, int>mp;
map<string, string>strmp;
vector<string>strvec, ans;
int main()
{
#ifdef _Aya
	freopen("out.txt", "w", stdout);
#endif
	string str, tmp;
	while (cin >> str && str != "#")
	{
		strvec.push_back(str);
		tmp = "";
		for (auto& i : str)
		{
			if (isupper(i))
				tmp += tolower(i);
			else
				tmp += i;
		}
		sort(tmp.begin(), tmp.end());
		strmp[str] = tmp;
		++mp[tmp];
	}
	for (auto& i : strvec)
		if (mp[strmp[i]] == 1)
			ans.push_back(i);
	sort(ans.begin(), ans.end());
	for (auto& i : ans)
		cout << i << endl;
	return 0;
}
