#include <iostream>
#include <vector>
#include <algorithm>
int num[200005], point[200005];
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> num[i];
	for (int i = 0; i < n; ++i)
		cin >> point[i];
	int st = 1, ans = m;
	for (int i = m - 2; i >= 0; --i)
	{
		while (num[i] + point[st] > num[m - 1] + point[0] && st < n)
			++st;
		if (st >= n)
			break;
		--ans, ++st;
	}
	cout << ans << endl;
	//system("pause");
	return 0;
}