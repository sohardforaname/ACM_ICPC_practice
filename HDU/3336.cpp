#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int nextarray[200005];
void getnext(string &str)
{
	memset(nextarray, 0, sizeof(nextarray));
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
	int n;
	cin >> n;
	string s;
	while (n--)
	{
		int m;
		cin >> m;
		cin >> s;
		getnext(s);
		int k = s.size() - nextarray[s.size()], ans = 0;
		for (int i = 1; i <= s.size();++i)
		{
			if (!nextarray[i])
				ans = (ans + 1) % 10007;
			else
				ans = ((nextarray[i] - 1) / k + 2 + ans) % 10007;
		}
		cout << ans << endl;
	}
	return 0;
}