#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
	int i;
	cin >> i;
	long long n, x, y, d, ans;
	while (i--)
	{
		ans = 0x3f3f3f3f3f3f3f3f;
		cin >> n >> x >> y >> d;
		if (abs(y - x) % d == 0)
			ans = min(ans, (abs(y - x) / d));
		if ((y - 1) % d == 0)
			ans = min(ans, (y - 1) / d + (x - 2) / d + 1);
		if ((n - y) % d == 0)
			ans = min(ans, (n - y) / d + (n - x - 1) / d + 1);
		if (ans == 0x3f3f3f3f3f3f3f3f)
			cout << -1 << endl;
		else
			cout << ans << endl;
	}
	return 0;
}