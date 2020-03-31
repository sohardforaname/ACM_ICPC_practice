#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int nextarray[1000005];
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
void solve(string &str, int kase)
{
	cout << "Test case #" << kase << endl;
	for (int i = 2; i <= str.size(); ++i)
	{
		if (nextarray[i] && i % (i - nextarray[i]) == 0)
			cout << i << " " << i / (i - nextarray[i]) << endl;
	}
	cout << endl;
}
int main()
{
	string a;
	int n, kase = 0;
	while (cin >> n && n)
	{
		cin >> a;
		getnext(a);
		solve(a, ++kase);
	}
	return 0;
}