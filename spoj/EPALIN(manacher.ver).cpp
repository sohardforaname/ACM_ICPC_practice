#include <cstdio>
#include <cstring> 
#define max(a,b) (a>b?a:b)
#define min(a,b) (a>b?b:a)
const int MAXN = 200005;
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
int ans[MAXN];
int main()
{
	while (~scanf("%s", s))
	{
		len = strlen(s);
		manacher();
		int ans = 0;
		for (int i = 1; i < 2 * len + 2; ++i)
		{
			if (i + mp[i] == len * 2 + 2)
				ans = max(ans, mp[i] - 1);
		}
		for (int i = 0; i < len - ans; ++i)
			printf("%c", s[i]);
		for (int i = len - ans; i < len; ++i)
			printf("%c", s[i]);
		for (int i = len - ans - 1; i >= 0; --i)
			printf("%c", s[i]);
		printf("\n");
	}
	return 0;
}