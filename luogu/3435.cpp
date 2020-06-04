#include <iostream>
#include <string>
using namespace std;
int nextarray[1000005];
void getnext(string &str)
{
	nextarray[0] = -1;
	int j = -1, k = 0;
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
	string str;
	cin >> str;
	getnext(str);
	long long ans = 0;
	for (int i = 1; i <= n; ++i)
		if (nextarray[nextarray[i]] > 0)
			nextarray[i] = nextarray[nextarray[i]];
	for (int i = 1; i <= n; ++i)
		if (nextarray[i])
			ans += i - nextarray[i];
	cout << ans << endl;
	return 0;
}