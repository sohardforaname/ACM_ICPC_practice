    #include <bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    const int MAXN = 2e5 + 5;
    int a[MAXN];
    ll sum[MAXN];
    ll ans[MAXN];
    int main()
    {
    	int n, m;
    	scanf("%d%d", &n, &m);
    	for (int i = 1; i <= n; ++i)
    		scanf("%d", &a[i]);
    	sort(a + 1, a + 1 + n);
    	for (int i = 1; i <= n; ++i)
    		sum[i] = sum[i - 1] + a[i];
    	for (int i = 1; i <= n; ++i)
    	{
    		ans[i] = sum[i] + (i - m > 0 ? ans[i - m] : 0);
    		printf("%lld%c", ans[i], i == n ? '\n' : ' ');
    	}
    	return 0;
    }