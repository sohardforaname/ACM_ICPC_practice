#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int nextarray[400005];
int ans[400005];
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
void solve(string &str)
{
	int i = 0, j = str.size();
	memset(ans, 0, sizeof(ans));
	ans[i++] = str.size();
	while (nextarray[j])
	{
		ans[i++] = nextarray[j];
		j = nextarray[j];
	}
	for (int k = i - 1; k >= 0; --k)
	{
		cout << ans[k];
		if (k > 0)
			cout << " ";
	}
	cout << endl;
}
int main()
{
	string a;
	while (cin >> a)
	{
		getnext(a);
		solve(a);
	}
	return 0;
}