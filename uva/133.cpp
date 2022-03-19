#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
bool vis[25];
int main()
{
	int n, k, m, prepo, nexpo, outtag, preind, nexind, ifdot;
	while (scanf("%d%d%d", &n, &k, &m) && n + k + m)
	{
		prepo = 1, nexpo = n, outtag = 0, preind = 1, nexind = 1;
		ifdot = 0;
		memset(vis, 0, sizeof(vis));
		while (outtag < n)
		{
			while (preind < k)
			{
				if (vis[prepo])
					++prepo;
				else
					++prepo, ++preind;
				if (prepo > n)
					prepo = 1;
			}
			while (nexind < m)
			{
				if (vis[nexpo])
					--nexpo;
				else
					--nexpo, ++nexind;
				if (nexpo < 1)
					nexpo = n;
			}
			while (vis[prepo])
			{
				++prepo;
				if (prepo > n)
					prepo = 1;
			}
			while (vis[nexpo])
			{
				--nexpo;
				if (nexpo < 1)
					nexpo = n;
			}
			if (prepo == nexpo)
			{
				vis[prepo] = 1;
				++outtag;
				if (!ifdot)
					ifdot = 1;
				else
					printf(",");
				printf("%3d", prepo);
				preind = nexind = 1;
			}
			else
			{
				vis[prepo] = 1;
				vis[nexpo] = 1;
				outtag += 2;
				if (!ifdot)
					ifdot = 1;
				else
					printf(",");
				printf("%3d%3d", prepo, nexpo);
				preind = nexind = 1;
			}
		}
		printf("\n");
	}
}