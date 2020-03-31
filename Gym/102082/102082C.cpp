#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5;
struct node
{
	int x, y, dist;
	bool operator<(const node& a)const
	{
		return dist > a.dist;
	}
};
node d[MAXN];
int main()
{
	int r, s, p;
	scanf("%d%d%d", &r, &s, &p);
	for (int i = 0; i < p; ++i)
	{
		scanf("%d%d", &d[i].x, &d[i].y);
		if (d[i].y <= s)
			d[i].dist = s - d[i].y + 1;
		else
			d[i].dist = d[i].y - s;
		d[i].dist += r - d[i].x + 1;
	}
	sort(d, d + p);
	int ans = 0, k = 0;
	for (int i = 0; i < p; ++i)
		ans = max(ans, d[i].dist + k), ++k;
	printf("%d\n", ans);
	return 0;
} 
