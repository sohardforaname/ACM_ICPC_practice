#include <iostream>
#include <string>
#include <cstring>
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
void solve(string &str)
{
	getnext(str);
	int cir = str.size() - nextarray[str.size()];
	if (nextarray[str.size()] == 0)
		cout << str.size() << endl;
	else if (str.size() % cir == 0)
		cout << 0 << endl;
	else
		cout << cir - str.size() % cir << endl;
}
int main()
{
	int n;
	cin >> n;
	string a;
	while (n--)
	{
		cin >> a;
		solve(a);
	}
	return 0;
}