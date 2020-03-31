#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
bool isprime[N];
int prime[N], phi[N], cnt;
void getphi(int n)
{
	for (int i = 2; i < n; ++i)
		isprime[i] = 1;
	phi[1] = 1, cnt = 0;
	for (int i = 2; i < n; ++i)
	{
		if (isprime[i])
			prime[cnt++] = i, phi[i] = i - 1;
		for (int j = 0; j < cnt && i * prime[j] < n; ++j)
		{
			isprime[i * prime[j]] = 0;
			if (i % prime[j] == 0)
			{
				phi[i * prime[j]] = phi[i] * prime[j];
				break;
			}
			else
				phi[i * prime[j]] = phi[i] * phi[prime[j]];
		}
	}
}
int main()
{
	getphi(N);
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		printf("%d\n", phi[n]);
	}
	return 0;
}