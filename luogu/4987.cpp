#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
char ma[N << 1];
int mp[N << 1];
char s[N];
int len;
void manacher()
{
	int l = 0;
	ma[l++] = '$';
	ma[l++] = '#';
	for (int i = 0; i < len; ++i)
	{
		ma[l++] = s[i];
		ma[l++] = '#';
	}
	ma[l] = 0;
	int mx = 0, id = 0;
	for (int i = 0; i < l; ++i)
	{
		mp[i] = mx > i ? min(mp[2 * id - i], mx - i) : 1;
		while (ma[i + mp[i]] == ma[i - mp[i]])
			++mp[i];
		if (i + mp[i] > mx)
		{
			mx = i + mp[i];
			id = i;
		}
	}
}
bool vis[N];
int main()
{
	int n, l;
	scanf("%d%d", &n, &l);
	scanf("%s", s);
	for (int i = 0; i < n; ++i)
		s[i + n] = s[i];
	len = strlen(s);
	manacher();
	int ans = 0;
	for (int i = 2; i <= 2 * len + 1; ++i)
	{
		int spos = (i - 2) / 2;
		if ((mp[i] - 1) % 2 && mp[i] - 1 >= l && !vis[spos % n])
			++ans, vis[spos % n] = 1;
	}
	printf("%d\n", ans);
	return 0;
}