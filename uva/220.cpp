#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
char mp[10][10];
int d[8][2] = { {-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1} }, num[2];
char cur;
map<char, int>m;
void init()
{
	m['W'] = 0;
	m['B'] = 1;
}
void ex()
{
	if (cur == 'W')
		cur = 'B';
	else
		cur = 'W';
}
bool check(int x, int y)
{
	if (x > 7 || x < 0 || y > 7 || y < 0)
		return 0;
	return 1;
}
int judge(int x, int y, int dx, int dy)
{
	int t = 0;
	while (check((x += dx), (y += dy)))
	{
		if (mp[x][y] == '-')
			return 0;
		if (mp[x][y] == cur)
			return t;
		++t;
	}
	return 0;
}
bool L(bool isp)
{
	int n = 0;
	bool f = 0;
	for (int i = 0; i < 8; ++i)
		for (int j = 0; j < 8; ++j)
			if (mp[i][j] == '-')
				for (int k = 0; k < 8; ++k)
					if (judge(i, j, d[k][0], d[k][1]))
					{
						if (isp)
						{
							if (f)
								putchar(' ');
							printf("(%d,%d)", i + 1, j + 1);
						}
						else
							return 1;
						if (!f)
							f = 1;
						++n;
						break;
					}
	if (isp)
	{
		if (!n)
			printf("No legal move.\n");
		else
			putchar('\n');
	}
	return 0;
}
void Q()
{
	for (int i = 0; i < 8; ++i)
		printf("%s\n", mp[i]);
}
void change(int x, int y, int dx, int dy, int t)
{
	while (t--)
	{
		mp[(x += dx)][(y += dy)] = cur;
		++num[m[cur]], --num[1 ^ m[cur]];
	}
}
void M(int x,int y)
{
	bool flag = 0;
	if (!L(0))
		ex();
	mp[x][y] = cur;
	++num[m[cur]];
	int st;
	for (int i = 0; i < 8; ++i)
		if (st = judge(x, y, d[i][0], d[i][1]))
			change(x, y, d[i][0], d[i][1], st);
	printf("Black - %2d White - %2d\n", num[1], num[0]);
	ex();
}
char cmd[5];
int main()
{
	init();
	int T;
	scanf("%d", &T);
	while (T--)
	{
		memset(num, 0, sizeof(num));
		memset(mp, 0, sizeof(mp));
		for (int i = 0; i < 8; ++i)
			scanf("%s", mp[i]);
		for (int i = 0; i < 8; ++i)
			for (int j = 0; j < 8; ++j)
			{
				if (mp[i][j] != '-')
					++num[m[mp[i][j]]];
			}
		scanf("%s", cmd);
		cur = cmd[0];
		while (scanf("%s", cmd) && cmd[0] != 'Q')
		{
			if (cmd[0] == 'L')
				L(1);
			else if (cmd[0] == 'M')
				M(cmd[1] - '1', cmd[2] - '1');
		}
		Q();
		if(T)
			putchar('\n');
	}
	return 0;
}
