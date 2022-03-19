#include <iostream>
#include <string>
using namespace std;
struct node
{
	string str;
	int dir;
}p[100005];
int main()
{
	int n, m, a, b;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> p[i].dir >> p[i].str;
	int pos = 0;
	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b;
		if (a == 0 && p[pos].dir == 1)//Õ‚◊Û£¨À≥
		{
			pos += b;
			if (pos >= n)
				pos -= n;
		}
		else if (a == 1 && p[pos].dir == 1)//Õ‚”“£¨ƒÊ
		{
			pos -= b;
			if (pos < 0)
				pos += n;
		}
		else if (a == 0 && p[pos].dir == 0)//ƒ⁄◊Û£¨ƒÊ
		{
			pos -= b;
			if (pos < 0)
				pos += n;
		}
		else if (a == 1 && p[pos].dir == 0)//ƒ⁄”“£¨À≥
		{
			pos += b;
			if (pos >= n)
				pos -= n;
		}
	}
	cout << p[pos].str << endl;
	return 0;
}