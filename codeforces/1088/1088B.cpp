#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
long long num[100005];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; ++i)

		cin >> num[i];
	sort(num, num + n);
	int pos = 0; long long lazy = 0;
	int i;
	for (i = 0; i < k&&pos < n; ++i)
	{
		cout << num[pos] - lazy << endl;
		lazy += num[pos] - lazy;
		while (pos < n&&num[pos] - lazy <= 0)
			++pos;
	}
	while (i < k)
	{
		cout << 0 << endl;
		++i;
	}
	return 0;
}