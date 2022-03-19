    #include <bits/stdc++.h>
    using namespace std;
    const int N = 5e3+ 5;
    typedef long long ll; 
    int a[N];
    void solve()
    {
    	int n;
    	scanf("%d", &n);
    	for (int i = 1; i <= n; ++i)
    		scanf("%d", &a[i]);
    	for (int i = 1; i <= n; ++i)
    		for (int j = i + 1; j <= n; ++j)
    			if (a[i] == a[j] && j != i + 1)
    			{
    				printf("YES\n");
    				return;
    			}
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