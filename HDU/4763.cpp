#include <iostream>
#include <string>
#include <cstring>
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
bool kmp(string &a, string &b)
{
	int j = 0, k = 0;
	while (j < a.size() && k < b.size())
	{
		if (j == -1 || a[j] == b[k])
			++j, ++k;
		else
			k = nextarray[k];
	}
	if (k >= b.size())
		return true;
	return false;
}
int main()
{
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	while (n--)
	{
		string str, tmp1, tmp2;
		cin >> str;
		getnext(str);
		if (!nextarray[str.size()] || str.size() < 3)
			cout << 0 << endl;
		else
		{
			int len = str.size();
			while (nextarray[len] > str.size() / 3)
				len = nextarray[len];
			while (nextarray[len])
			{
				tmp1 = str.substr(nextarray[len], str.size() - nextarray[len] * 2);
				tmp2 = str.substr(0, nextarray[len]);
				if (kmp(tmp1, tmp2))
					break;
				else
					len = nextarray[len];
			}
			cout << nextarray[len] << endl;
		}
	}
		return 0;
}