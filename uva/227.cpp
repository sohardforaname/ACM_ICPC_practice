#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;
char chs[5][5];
bool flag = 0;
bool check(int i, int j)
{
	if (i < 0 || j < 0 || i > 4 || j > 4)
		return false;
	return true;
}
#define Aya
int main()
{
#ifdef Aya
	freopen("D:\\in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	string a;
	int index = 0;
	while (getline(cin, a) && a != "Z")
	{
		flag = 0;
		for (int i = 0; i < 5; ++i)
			chs[0][i] = a[i];
		for (int i = 0; i < 4; ++i)
		{
			getline(cin, a);
			for (int j = 0; j < 5; ++j)
				chs[i + 1][j] = a[j];
		}
		char ch;
		int sx, sy;
		for (int i = 0; i < 5; ++i)
			for (int j = 0; j < 5; ++j)
				if (chs[i][j] == ' ')
					sx = i, sy = j;
		/*for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; ++j)
				cout << chs[i][j]<<" ";
			cout << endl;
		}*/
		while (cin >> ch)
		{
			if (ch == '\n')
				continue;
			else if (ch == '0')
				break;
			if (flag == 0)
			{
				if (ch == 'A')
				{
					--sx;
					if (check(sx, sy))
						swap(chs[sx + 1][sy], chs[sx][sy]);
					else
						flag = 1;
				}
				else if (ch == 'B')
				{
					++sx;
					if (check(sx, sy))
						swap(chs[sx - 1][sy], chs[sx][sy]);
					else
						flag = 1;
				}
				else if (ch == 'R')
				{
					++sy;
					if (check(sx, sy))
						swap(chs[sx][sy - 1], chs[sx][sy]);
					else
						flag = 1;
				}
				else if (ch == 'L')
				{
					--sy;
					if (check(sx, sy))
						swap(chs[sx][sy + 1], chs[sx][sy]);
					else
						flag = 1;
				}
			}
			//cout << sx << " " << sy << endl;
		}
		if (index)
			cout << endl;
		cout << "Puzzle #" << ++index << ":" << endl;
		if (flag)
			cout << "This puzzle has no final configuration." << endl;
		else
			for (int i = 0; i < 5; ++i)
				for (int j = 0; j < 5; ++j)
				{
					cout << chs[i][j];
					if (j < 4)
						cout << ' ';
					else
						cout << endl;
				}
		getline(cin, a);
	}
	return 0;
}
