#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		long long a, b, n, s;
		scanf("%lld%lld%lld%lld", &a, &b, &n, &s);//a,n,b,1
		if (n * a + b < s)
			printf("NO\n");
		else if (s % n > b)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}