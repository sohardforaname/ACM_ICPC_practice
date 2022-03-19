#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int num[200005];
bool kind[200005];
int dripos[200005];
int pasnum[200005];
int main()
{
	int n, m;
	cin >> n >> m;//nÈËmË¾»ú
	for (int i = 0; i < n + m; ++i)
		cin >> num[i];
	int cnt = 0;
	for (int i = 0; i < n + m; ++i)
	{
		cin >> kind[i];
		if (kind[i] == 1)
			dripos[cnt++] = num[i];
	}
	int i, j;
	for (i = 0; i < n + m && num[i] < dripos[0]; ++i)
		++pasnum[0];
	for (j = n + m - 1; num[j] > dripos[cnt - 1]; --j)
		++pasnum[cnt - 1];
	int pos = 0;
	for (i; i <= j; ++i)
	{
		if (kind[i] == 0)
		{
			while (pos + 1 < cnt && dripos[pos + 1] < num[i])
				++pos;			
			if (pos + 1 < cnt && num[i] <= (dripos[pos] + dripos[pos + 1]) / 2)
				++pasnum[pos];
			else if (pos + 1 < cnt&&num[i] > (dripos[pos] + dripos[pos + 1]) / 2)
				++pasnum[pos + 1];
		}
	}
	for (int i = 0; i < cnt; ++i)
		cout << pasnum[i] << " ";
	cout << endl;
	return 0;
}