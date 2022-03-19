#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <cmath>
using namespace std;
int main()
{
	long long n, k;
	cin >> n >> k;
	long long ans = 0x3f3f3f3f3f3f3f3f;
	for (int i = 1; i < k; ++i)
	{
		if ((n*k + i * i) % i == 0 && n % i == 0)
			ans = min(ans, (n*k + i * i) / i);
	}
	cout << ans << endl;
	return 0;
}