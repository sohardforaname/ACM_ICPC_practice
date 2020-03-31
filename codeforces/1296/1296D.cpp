    #include <bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    const int N = 2e5 + 5;
    int m[N], lef[N];
    void solve()
    {
    	int n,a,b,k;
    	scanf("%d%d%d%d", &n, &a, &b, &k);
    	for (int i = 1; i <= n; ++i)
    		scanf("%d", &m[i]);
    	for (int i = 1; i <= n; ++i)
    	{
    		int tmp = m[i] % (a + b);
    		if (tmp == 0)//刚好b打死了
    			lef[i] = (a + b - 1) / a;
    		else if (tmp <= a)//a一下子打死
    			lef[i] = 0;
    		else if (tmp > a)//a一下子打不死
    			lef[i] = (tmp - 1) / a;
    	}
    	sort(lef + 1, lef + n + 1);
    	int p = 0;
    	for (int i = 1; i <= n; ++i)
    		if (k >= lef[i])
    			++p, k -= lef[i];
    	printf("%d\n", p);
    }
    int main()
    {
    	int t = 1;
    	//scanf("%d", &t);
    	while (t--)
    		solve();
    	return 0;
    }