#include <iostream>
using namespace std;
char ch[1005][1005];
char chnew[1005][1005];
bool check(int x, int y)
{
	for (int i = x - 1; i < x + 2; ++i)
		for (int j = y - 1; j < y + 2; ++j)
			if (i != x || j != y)
				if (ch[i][j] != '#')
					return false;
	return true;
}
void forge(int x, int y)
{
	for (int i = x - 1; i < x + 2; ++i)
		for (int j = y - 1; j < y + 2; ++j)
			if (i != x || j != y)
				chnew[i][j] = '#';
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n + 2; ++i)
		for (int j = 0; j < m + 2; ++j)
			chnew[i][j] = '.';
	for (int i = 1; i < n + 1; ++i)
	{
		//getchar();
		for (int j = 1; j < m + 1; ++j)
			cin >> ch[i][j];
	}
	for (int i = 1; i < n + 1; ++i)
	{
		for (int j = 1; j < m + 1; ++j)
			if (check(i, j))
				forge(i, j);
	}
	bool flag = 0;
	for (int i = 1; i < n + 1; ++i)
		for (int j = 1; j < m + 1; ++j)
			if (ch[i][j] != chnew[i][j])
				flag = 1;
	if (flag)
		cout << "No" << endl;
	else
		cout << "Yes" << endl;
	//system("pause");
	return 0;
}