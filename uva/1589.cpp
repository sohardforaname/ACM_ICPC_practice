#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
int hdir[8][2] = { {-2,-1},{-2,1},{2,-1},{2,1},{-1,-2},{1,-2},{-1,2},{1,2} };
bool del[12][12];
int ori[12][12];
bool isinrange(int x, int y)
{
	if (x > 0 && x < 10 && y>0 && y < 9)
		return true;
	return false;
}
bool isgeneralinrange(int x, int y)
{
	if (x > 0 && x < 4 && y>3 && y < 7)
		return true;
	return false;
}
bool black(int y)
{
	for (int i = 1; i < 11; ++i)
		if (ori[i][y] == 4)
			return 0;
		else if (ori[i][y] != 0 && ori[i][y] != 4)
			return 1;
	return 1;
}
void hor(int x, int y)
{
	for (int i = 0; i < 8; ++i)
		if (isinrange(x + hdir[i][0], y + hdir[i][1]) && ori[x + dir[i / 2][0]][y + dir[i / 2][1]] == 0)
			del[x + hdir[i][0]][y + hdir[i][1]] = 1;
}
void car(int x, int y, int val, int f)
{
	int flag = 0;
	for (int i = x - 1; i > 0; --i)
	{
		if (flag == f)
			del[i][y] = val;
		if (ori[i][y])
			++flag;
	}
	flag = 0;
	for (int i = x + 1; i < 11; ++i)
	{
		if (flag == f)
			del[i][y] = val;
		if (ori[i][y])
			++flag;
	}
	flag = 0;
	for (int i = y - 1; i > 0; --i)
	{
		if (flag == f)
			del[x][i] = val;
		if (ori[x][i])
			++flag;
	}
	flag = 0;
	for (int i = y + 1; i < 10; ++i)
	{
		if (flag == f)
			del[x][i] = val;
		if (ori[x][i])
			++flag;
	}
}
bool check(int x, int y)
{
	for (int i = 0; i < 4; ++i)
		if (isgeneralinrange(x + dir[i][0], y + dir[i][1]) && del[x + dir[i][0]][y + dir[i][1]] == 0)
			return 0;
	return 1;
}
struct node
{
	int type, x, y;
};
void print()
{
	for (int i = 1; i < 11; ++i)
		for (int j = 1; j < 10; ++j)
		{
			cout << ori[i][j];
			if (j < 10 - 1)
				cout << " ";
			else
				cout << endl;
		}
	cout << endl;
	for (int i = 1; i < 11; ++i)
		for (int j = 1; j < 10; ++j)
		{
			cout << del[i][j];
			if (j < 10 - 1)
				cout << " ";
			else
				cout << endl;
		}
}
node num[8];
int main()
{
	freopen("D:\\in.txt", "r", stdin);
	freopen("D:\\out.txt", "w", stdout);
	bool flag = 0;
	int n, bx, by;
	while (cin >> n >> bx >> by && n + bx + by)
	{
		flag = 0;
		memset(ori, 0, sizeof(ori));
		memset(del, 0, sizeof(del));
		char ch;
		for (int i = 0; i < n; ++i)
		{
			cin >> ch >> num[i].x >> num[i].y;
			if (ch == 'R')
			{
				num[i].type = 1;
				ori[num[i].x][num[i].y] = 1;
			}
			else if (ch == 'C')
			{
				num[i].type = 2;
				ori[num[i].x][num[i].y] = 2;
			}
			else if (ch == 'H')
			{
				num[i].type = 3;
				ori[num[i].x][num[i].y] = 3;
			}
			else if (ch == 'G')
			{
				num[i].type = 4;
				ori[num[i].x][num[i].y] = 4;
			}
		}
		if (!black(by))
		{
			cout << "NO" << endl;
			continue;
		}
		for (int i = 0; i < n; ++i)
		{
			if (num[i].type == 1 || num[i].type == 4)
				car(num[i].x, num[i].y, 1, 0);
			else if (num[i].type == 2)
				car(num[i].x, num[i].y, 1, 1);
			else if (num[i].type == 3)
				hor(num[i].x, num[i].y);
		}
		//print();
		if (check(bx, by))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		getchar();
	}
	return 0;
}
