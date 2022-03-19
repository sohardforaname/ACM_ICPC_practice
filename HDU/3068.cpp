#include <cstdio>
#include <cstring> 
#define max(a,b) (a>b?a:b)
#define min(a,b) (a>b?b:a)
const int MAXN = 1100005;
char ma[MAXN << 1];
int mp[MAXN << 1];
char s[MAXN];
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
int main()
{
	while (~scanf("%s", s))
	{
		len = strlen(s);
		manacher();
		int ans = 0;
		for (int i = 0; i < 2 * len + 2; ++i)
			ans = max(ans, mp[i] - 1);
		printf("%d\n", ans);
	}
	return 0;
}