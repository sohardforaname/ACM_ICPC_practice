#include <iostream>
using namespace std;
int num[10010][15][2];
const int ping[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int run[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int getnum(int y, int m)
{
	if ((y < 1582 && y % 4 == 0) || y == 1700)
		return run[m - 1];
	else if (y >= 1582 && ((y % 4 == 0 && y % 100) || y % 400 == 0))
		return run[m - 1];
	else
		return ping[m - 1];
}
void init()
{
	num[0][12][0] = 0, num[0][12][1] = 0;
	int x, s = 5;
	for (int i = 1; i < 10005; ++i)
	{
		for (int j = 1; j <= 12; ++j)
		{
			x = getnum(i, j);
			//cout << i << j << s << endl;
			for (int k = 1; k <= x; ++k)
			{
				if (k == 1)
				{
					if (s == 5 || s == 6 || s == 0) //周六周日周一
					{
						if (j != 1)
							num[i][j][0] = num[i][j - 1][0] + 1;
						else
							num[i][j][0] = num[i - 1][12][0] + 1;
					}
					else
					{
						if (j != 1)
							num[i][j][0] = num[i][j - 1][0];
						else
							num[i][j][0] = num[i - 1][12][0];
					}
				}
				else if (k == x)
				{
					if (s == 4 || s == 5 || s == 6) //周五周六周日
					{
						if (j != 1)
							num[i][j][1] = num[i][j - 1][1] + 1;
						else
							num[i][j][1] = num[i - 1][12][1] + 1;
					}
					else
					{
						if (j != 1)
							num[i][j][1] = num[i][j - 1][1];
						else
							num[i][j][1] = num[i - 1][12][1];
					}
				}
				if (i != 1752 || j != 9 || (k > 13 || k < 3))
				{
					++s;
					if (s == 7)
						s = 0;
				}
			}
			//cout << i << j << s << endl;
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	init();
	int n, a, b, c, d;
	cin >> n;
	while (n--)
	{
		cin >> a >> b >> c >> d;
		if (b != 1)
			cout << num[c][d][1] - num[a][b - 1][1] << " " << num[c][d][0] - num[a][b - 1][0] << endl;
		else
			cout << num[c][d][1] - num[a - 1][12][1] << " " << num[c][d][0] - num[a - 1][12][0] << endl;
	}
	return 0;
}