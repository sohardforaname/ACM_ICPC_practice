#include <iostream>
#include <algorithm>
using namespace std;
long long num[200005];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i)
		cin >> num[i];
	sort(num, num + n);
	long long ans = 0;
	int mod = m / (k + 1);
	ans += (num[n - 1] * k + num[n - 2])*mod;
	ans += num[n - 1] * (m % (k + 1));
	cout << ans << endl;
	return 0;
}