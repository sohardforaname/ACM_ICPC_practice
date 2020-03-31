#include <iostream>
using namespace std;
int num[10005][4];
int main()
{
	int n, x, y, a = 0;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> num[i][0] >> num[i][1] >> num[i][2] >> num[i][3];
	cin >> x >> y;
	for (int i = 1; i <= n; ++i)
	{
		if (x >= num[i][0] && x <= num[i][0] + num[i][2] && y >= num[i][1] && y <= num[i][1] + num[i][3])
			a = i;
	}
	if (a)
		cout << a << endl;
	else
		cout << -1 << endl;
	return 0;
}