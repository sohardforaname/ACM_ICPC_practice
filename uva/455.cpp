#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;
int nexts[100];
string str;
void getnext(string &str)
{
	memset(nexts, 0, sizeof(nexts));
	nexts[0] = -1;
	int k = 0, j = -1;
	while (k < str.size())
	{
		if (j == -1 || str[j] == str[k])
			nexts[++k] = ++j;
		else
			j = nexts[j];
	}
}
int main()
{
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	while (n--)
	{
		cin >> str;
		getnext(str);
		int k;
		if (str.size() % (str.size() - nexts[str.size()]) == 0)
			k = str.size() - nexts[str.size()];
		else
			k = str.size();
		if (n > 0)
			cout << k << endl << endl;
		else
			cout << k << endl;
	}
	return 0;
}