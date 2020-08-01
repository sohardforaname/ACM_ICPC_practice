#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll pow(ll a, ll b, ll p)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        if (n == 1)
            printf("26\n");
        else if (n == 2)
            printf("676\n");
        else if (n == 3)
            printf("17576\n");
        else
            printf("15600\n");
    }
    return 0;
}