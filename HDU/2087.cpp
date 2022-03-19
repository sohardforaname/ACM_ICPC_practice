#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int nextarray[1005];
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
int count(string &a, string &b)
{
	int i = 0, j = 0, ans = 0;
	while (i < a.size())
	{
		if (j == -1 || a[i] == b[j])
			++i, ++j;
		else
			j = nextarray[j];
		if (j == b.size())
			++ans, j = 0;
	}
	return ans;
}
int main()
{
	string a, b;
	while (cin >> a && a != "#")
	{
		cin >> b;
		getnext(b);
		cout << count(a, b) << endl;
	}
	return 0;
}