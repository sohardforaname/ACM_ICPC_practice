#include <bits/stdc++.h>
using namespace std;
int l[1005], r[1005];
int num[1005];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> l[i];
	for (int i = 0; i < n; ++i)
		cin >> r[i];
	if (l[0] > 0 || r[n - 1] > 0)
	{
		cout << "NO" << endl;
		return 0;
	}
	for (int i = 0; i < n; ++i)
		num[i] = n - r[i] - l[i];
	for (int i = 0; i < n; ++i)
	{
		int tmpl = 0, tmpr = 0;
		for (int j = 0; j < i; ++j)
			if (num[j] > num[i])
				++tmpl;
		for (int j = i + 1; j < n; ++j)
			if (num[j] > num[i])
				++tmpr;
		if (tmpl != l[i] || tmpr != r[i])
		{
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	for (int i = 0; i < n; ++i)
		cout << num[i] << " ";
	cout << endl;
	return 0;
}