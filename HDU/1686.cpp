#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int nextarray[10005];
void getnext(string &a)
{
	memset(nextarray, 0, sizeof(nextarray));
	int k = 0, j = -1;
	nextarray[0] = -1;
	while (k != a.size())
	{
		if (j == -1 || a[j] == a[k])
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
			++ans, j = nextarray[j];
	}
	return ans;
}
int main()
{
	int n;
	cin >> n;
	string a, b;
	while (n--)
	{
		cin >> a >> b;
		getnext(a);
		cout << count(b, a) << endl;
	}
	return 0;
}