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
	string str;
	int n;
	cin >> n;
	cin >> str;
	getnext(str);
	cout << str.size() - nextarray[str.size()];
	return 0;
}