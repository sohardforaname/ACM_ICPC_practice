#include <iostream>
#include <string>
#include <vector>
using namespace std;
int nextarray[1000005];
void getnext(string &str)
{
	int j = -1, k = 0;
	nextarray[0] = -1;
	while (k < str.size())
	{
		if (j == -1 || str[j] == str[k])
			nextarray[++k] = ++j;
		else
			j = nextarray[j];
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	string s;
	vector<int>ans;
	for (int i = 1; i <= n; ++i)
	{
		ans.clear();
		cin >> s;
		getnext(s);
		int len = nextarray[s.size()];
		while (len)
		{
			ans.push_back(s.size() - len);
			len = nextarray[len];
		}
		ans.push_back(s.size());
		cout << "Case #" << i << ": " << ans.size() << endl;
		for (int i = 0; i < ans.size(); ++i)
		{
			cout << ans[i];
			if (i < ans.size() - 1)
				cout << " ";
			else
				cout << endl;
		}
	}
	return 0;
}