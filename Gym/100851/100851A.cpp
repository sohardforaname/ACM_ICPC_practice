#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
typedef long long ll;
vector<ll>rd, cd;
ll rdsum, cdsum;
ll rsum[N], csum[N];
int main()
{
	freopen("adjustment.in", "r", stdin);
	freopen("adjustment.out", "w", stdout);
	ll n, q;//这里不用ll应该也可，但是不值得冒这个险
	scanf("%lld%lld", &n, &q);
	rsum[1] = (2ll + n + 1ll) * n / 2;
	for (int i = 2; i <= n; ++i)
		rsum[i] = rsum[i - 1] + n;
	for (int i = 1; i <= n; ++i)
		csum[i] = rsum[i];
	char op[2];
	ll p = 0;//p不用ll会溢出
	for (int i = 1; i <= q; ++i)
	{
		scanf("%s%lld", op, &p);
		if (op[0] == 'R')
		{
			if (!rsum[p])
				printf("0\n");
			else
			{
				rdsum += p;
				printf("%lld\n", rsum[p] - (ll)cd.size() * p - cdsum);
				rsum[p] = 0;
				rd.push_back(p);
			}
		}
		else if (op[0] == 'C')
		{
			if (!csum[p])
				printf("0\n");
			else
			{
				cdsum += p;
				printf("%lld\n", csum[p] - (ll)rd.size() * p - rdsum);
				csum[p] = 0;
				cd.push_back(p);
			}
		}
	}
	return 0;
}