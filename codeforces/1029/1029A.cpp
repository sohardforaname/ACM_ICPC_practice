#include <iostream>
#include <string>
using namespace std;
int  nextarray[55];
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
	int n, m;
	cin >> n >> m;
	string a;
	cin >> a;
	getnext(a);
	int p = n - nextarray[n];
	for (int i = 0; i < m - 1; ++i)
		for (int j = 0; j < p; ++j)
			cout << a[j];
	cout << a;
	cout << endl;
	return 0;
}