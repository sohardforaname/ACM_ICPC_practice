#include <iostream>
using namespace std;
int num[200005];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> num[i];
	int f, x;
	cin >> x >> f;
	long long ans = 0;
	for (int i = 0; i < n; ++i)
	{
		int lef = num[i] % (f + x), divnum = num[i] / (f + x);
		if (lef > x)
			ans += (divnum + 1) * f;
		else
			ans += divnum * f;
	}
	cout << ans << endl;
	system("pause");
	return 0;
}