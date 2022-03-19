#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
typedef long long ll;
ll dp[N], sumt[N], sumc[N];
int q[N];
ll getx(int i, int j)
{
	return sumc[j] - sumc[i];
}
ll gety(int i, int j)
{
	return dp[j] - dp[i];
}
int check(int h, int t, int k)
{
	if (h == t - 1)
		return q[h];
	int l = h, r = t - 1;
	while (l < r)
	{
		int mid = (l + r) >> 1;
		if (gety(q[mid], q[mid + 1]) <= k * getx(q[mid], q[mid + 1]))
			l = mid + 1;
		else
			r = mid;
	}
	return q[l];
}
int main()
{
	int n, a, b;
	ll s;
	scanf("%d%lld", &n, &s);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d%d", &a, &b);
		sumt[i] = sumt[i - 1] + a;
		sumc[i] = sumc[i - 1] + b;
	}
	int head = 1, tail = 1;
	q[tail++] = 0;
	for (int i = 1; i <= n; ++i)
	{
		int p = check(head, tail, s + sumt[i]);
		dp[i] = dp[p] - (sumt[i] + s) * sumc[p] + sumt[i] * sumc[i] + s * sumc[n];
		while (head < tail - 1 && gety(q[tail - 2], q[tail - 1]) * getx(q[tail - 1], i) >= gety(q[tail - 1], i) * getx(q[tail - 2], q[tail - 1]))
			--tail;
		q[tail++] = i;
	}
	printf("%lld\n", dp[n]);
	return 0;
}
/*
def. dp[i]=min _{0<j<i} {dp[j]+sumt[i]*(sumc[i]-sumc[j])+s*(sumc[N]-sumc[j])}
	 dp[i]=min _{0<j<i} {dp[j]-(sumt[i]+s)*sumc[j]}+sumt[i]*sumc[i]+s*sumc[N]
	 dp[i]=dp[j]-(sumt[i]+s)*sumc[j]+sumt[i]*sumc[i]+s*sumc[N]
	 dp[j]=(sumt[i]+s)*sumc[j]+dp[i]-sumt[i]*sumc[i]-s*sumc[N]
def. yj=dp[j], xj=sumc[j] ==> k=sumt[i]+s b=dp[i]-sum[t]sumc[i]-s*sumc[N]
k<j, dp[j]-(sumt[i]+s)*sumc[j]<dp[k]-(sumt[i]+s)*sumc[k]
     dp[j]-dp[k]-(sumc[j]-sumc[k])<sumt[i]+s
*/