#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int num[105];
int main()
{
	int n, m, tmp;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> m;
		for (int i = 0; i < m; ++i)
		{
			cin >> tmp;
			++num[tmp];
		}
	}
	bool f = 0;
	for (int i = 1; i < 101; ++i)
		if (num[i] == n)
		{
			if (!f)
				cout << i, f = 1;
			else
				cout << " " << i;
		}
	cout << endl;
	return 0;
}