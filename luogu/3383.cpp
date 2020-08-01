#include <bits/stdc++.h>
using namespace std;
int prime[1000005];
bool isprime[10000005];
int tot = 0;
void getprime(int n)
{
    for (int i = 0; i <= n; ++i)
        isprime[i] = 1;
    isprime[1] = 0;
    for (int i = 2; i <= n; ++i)
    {
        if (isprime[i])
            prime[tot++] = i;
        for (int j = 0; j < tot && i * prime[j] <= n; ++j)
        {
            isprime[i * prime[j]] = 0;
            if (i % prime[j] == 0)
                break;
        }
    }
}
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    getprime(n);
    for (int i = 0; i < k; ++i)
    {
        scanf("%d", &n);
        printf("%s", (isprime[n] ? "Yes\n" : "No\n"));
    }
    return 0;
}
