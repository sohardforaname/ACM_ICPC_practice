#include <bits/stdc++.h>
using namespace std;
int num[1005];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> num[i];
	int ans = 1e8, tmp, index = 0;
	for (int i = 1; i < 101; ++i)
	{
		tmp = 0;
		for (int j = 0; j < n; ++j)
		{
			if (abs(num[j] - i) > 1)
				tmp += abs(num[j] - i) - 1;
		}
		if (ans > tmp)
			ans = tmp, index = i;
	}
	cout << index << " " << ans << endl;
	return 0;
}