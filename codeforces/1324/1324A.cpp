#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+ 5;
typedef long long ll; 
void solve()
{
	int n;
	scanf("%d", &n);
	int cnt = 0, a;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &a);
		cnt += a % 2;
	}
	if (cnt == n || cnt == 0)
		printf("YES\n");
	else
		printf("NO\n");
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}