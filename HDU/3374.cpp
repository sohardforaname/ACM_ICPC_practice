#include <iostream>
#include <string>
#include <cstring>
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
int getmin(string str)
{
	int i = 0, j = 1, k = 0;
	while (i < str.size() && j < str.size() && k < str.size())
	{
		int t = str[(i + k) % str.size()] - str[(j + k) % str.size()];
		if (t == 0)
			++k;
		else
		{
			if (t < 0)
				j += k + 1;	
			else if (t > 0)
				i += k + 1;
			if (i == j)
				++j;
			k = 0;
		}
	}
	return i > j ? j : i;
}
int getmax(string str)
{
	int i = 0, j = 1, k = 0;
	while (i < str.size() && j < str.size() && k < str.size())
	{
		int t = str[(i + k) % str.size()] - str[(j + k) % str.size()];
		if (t == 0)
			++k;
		else
		{
			if (t < 0)
				i += k + 1;
			else if (t > 0)
				j += k + 1;
			if (i == j)
				++j;
			k = 0;
		}
	}
	return i > j ? j : i;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	while (cin >> s)
	{
		getnext(s);
		int minpos = getmin(s), maxpos = getmax(s);
		int times = s.size() / (s.size() - nextarray[s.size()]);
		cout << minpos + 1 << " " << times << " " << maxpos + 1 << " " << times << endl;
	}
	return 0;
}