#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
int mu[MAXN], prime[MAXN];
bool isprime[MAXN];
int cnt = 0;
void calc()
{
	for (int i = 2; i < MAXN; ++i)
		isprime[i] = 1;
	for (int i = 2; i < MAXN; ++i)
	{
		if (isprime[i])
			prime[cnt++] = i, mu[i] = -1;
		int d;
		for (int j = 0; j < cnt && (d = prime[j] * i) < MAXN; ++j)
		{
			isprime[d] = 0;
			if (i % prime[j] == 0)
				mu[d] = 0;
			else
				mu[d] = -mu[i];
		}
	}
}
int main() 
{
	calc();
	return 0;
}
