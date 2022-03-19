#include <cstdio>
#include <cstdlib>
#include <cstring> 
using namespace std;
int mp[4][4], mp1[4][4];
int dir[5][2] = { {0, 0}, {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
bool check(int x, int y)
{
	if (x < 0 || x > 3 || y < 0 || y > 3)
		return false;
	return true;
}
void rot(int x, int y)
{
	for (int i = 0; i < 5; ++i)
		if (check(x + dir[i][0], y + dir[i][1]))
			mp[x + dir[i][0]][y + dir[i][1]] ^= 1;
}
bool check()
{
	int tag = 0;
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			tag += mp[i][j];
	return tag == 0 || tag == 16;
}
char str[5];
int main()
{
	for (int i = 0; i < 4; ++i)
	{
		scanf("%s", str);
		for (int j = 0; j < 4; ++j)
			mp1[i][j] = str[j] == 'b' ? 1 : 0;
	}
	int minn = 20;
	for (int i = 0; i < (1 << 16); ++i)
	{
		memcpy(mp, mp1, sizeof(mp1));
		int tmp = 0;
		for (int j = 0; j < 16; ++j)
			if ((1 << j) & i)
				rot(j / 4, j % 4), ++tmp;
		if (check() && tmp < minn)
			minn = tmp;
	}
	if (minn < 20)
		printf("%d\n", minn);
	else
		printf("Impossible\n");
	return 0;
}