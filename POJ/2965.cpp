#include <cstdio>
#include <cstring>
using namespace std;
bool mp[5][5];
bool check()
{
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			if (!mp[i][j])
				return 0;
	return 1;
}
void rotate(int pos)
{
	int x = pos / 4, y = pos % 4;
	for (int i = 0; i < 4; ++i)
		mp[x][i] ^= 1, mp[i][y] ^= 1;
	mp[x][y] ^= 1;
}
int sta[20], top;
int ans[20], anstop = 20;
void dfs(int beg, int div)
{
	if (check() && top < anstop)
	{
		memcpy(ans, sta, sizeof(sta));
		anstop = top;
		return;
	}
	for (int i = beg + 1; i < 16; ++i)
	{
		rotate(i);
		sta[top++] = i;
		dfs(i, div + 1);
		rotate(i);
		--top;
	}
	return;
}
char str[5];
int main()
{
	for (int i = 0; i < 4; ++i)
	{
		scanf("%s", str);
		for (int j = 0; j < 4; ++j)
			mp[i][j] = str[j] == '-' ? 1 : 0;
	}
	dfs(-1, 0);
	printf("%d\n", anstop);
	for (int i = 0; i < anstop; ++i)
		printf("%d %d\n", ans[i] / 4 + 1, ans[i] % 4 + 1);
	return 0;
}
