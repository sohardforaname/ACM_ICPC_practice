#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, a, b, c;
	cin >> n;
	while (n--)
	{
		cin >> a >> b >> c;
		if (a > c&&b > c)
			cout << c << endl;
		else if (a < c&&b < c)
			cout << c << endl;
		else
		{
			if (b%c == 0)
				cout << b + c << endl;
			else
				cout << c * (b / c + 1) << endl;
		}
	}
	return 0;
}