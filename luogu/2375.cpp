#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
int fail[MAXN];
int cnt[MAXN];
int mod = 1e9 + 7;
void getnext(string& str)
{
	fail[0] = -1;
	cnt[0] = 0;
	cnt[1] = 1;
	int j = 0, k = 1;
	while (k < str.size())
	{
		while (j && str[k] != str[j])
			j = fail[j];
		if (str[k++] == str[j])
			++j;
		fail[k] = j;
		cnt[k] = cnt[j] + 1;
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string a;
	int n;
	cin >> n;
	while (n--)
	{
		cin >> a;
		getnext(a);
		long long ans = 1;
		int j = 0;
		for (int i = 1; i < a.size(); ++i)
		{
			while (j && a[i] != a[j])
				j = fail[j];
			if (a[i] == a[j])
				++j;
			while ((j << 1) > i + 1)
				j = fail[j];
			ans = (ans * (cnt[j] + 1)) % mod;
		}
		cout << ans << endl;
	}
	return 0;
}