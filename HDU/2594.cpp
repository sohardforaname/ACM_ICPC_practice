#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
int nextarray[100005];
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
	string a, b, ans;
	while (cin >> a >> b)
	{
		int a_len = a.size(), b_len = b.size();
		a += b;
		getnext(a);
		ans = "";
		int len = nextarray[a.size()];
		while (len > a_len || len > b_len)
			len = nextarray[len];
		for (int i = 0; i < len; ++i)
			ans += a[i];
		if (len)
			cout << ans << " ";
		cout << len << endl;
	}
	return 0;
}