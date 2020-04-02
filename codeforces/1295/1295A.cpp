#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
void solve()
{
	int n;
	scanf("%d", &n);
	if (n % 2)
	{
		printf("7");
		for (int i = 0; i < (n - 3) / 2; ++i)
			printf("1");
		printf("\n");
	}
	else
	{
		for (int i = 0; i < n / 2; ++i)
			printf("1");
		printf("\n");
	}
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}