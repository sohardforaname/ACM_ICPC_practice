#include <iostream>
using namespace std;
int num[105];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i <= n; ++i)
		cin >> num[i];
	bool flag = 0;
	for (int i = 0; i <= n; ++i)
	{
		if (num[i] == 0)
			continue;
		flag = 1;
		if (num[i] != 1 && num[i] != -1)
		{
			if (num[i] > 0)
			{
				if (i != 0)
					cout << '+';
			}
			cout << num[i];
		}
		else if (num[i] == 1)
		{
			if (i != 0)
				cout << '+';
			if (i == n)
				cout << num[i];
		}
		else if (num[i] == -1)
		{
			cout << '-';
			if (i == n)
				cout << 1;
		}
		if (i < n - 1)
			cout << "x^" << n - i;
		else if (i == n - 1)
			cout << "x";
	}
	if (flag == 0)
		cout << 0 << endl;
	cout << endl;
	return 0;
}