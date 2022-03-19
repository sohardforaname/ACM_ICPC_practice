#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cassert>
using namespace std;
const int N = 16;
int G[N][N], tmp[N][N];
int n;
bool chk(int n)
{
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (tmp[i][j])
				return false;
	return true;
}
bool chkpos(int x, int y)
{
	return x > -1 && x < n && y > -1 && y < n;
}
void rot(int x, int y)
{
	for (int i = -1; i < 2; ++i)
	{
		if (chkpos(x, y + i))
			tmp[x][y + i] ^= 1;
		if (chkpos(x + i, y))
			tmp[x + i][y] ^= 1;
	}
	tmp[x][y] ^= 1;
}
char ch[N];
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
		{
			scanf("%s", ch);
			for (int j = 0; j < n; ++j)
				G[i][j] = ch[j] == 'y' ? 0 : 1;
		}
		int ans = 300;
		for (int i = 0; i < (1 << n); ++i)
		{
			memcpy(tmp, G, sizeof(G));
			int cnt = 0;
			for (int j = 0; j < n; ++j)
				if ((i >> j) & 1)
					++cnt, rot(0, j);
			for (int j = 1; j < n; ++j)
				for (int k = 0; k < n; ++k)
					if (tmp[j - 1][k])
						rot(j, k), ++cnt;
			if (chk(n))
				ans = min(ans, cnt);
		}
		if (ans == 300)
			printf("inf\n");
		else
			printf("%d\n", ans);
	}
	return 0;
}