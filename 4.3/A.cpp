#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
typedef long long ll;
int main()
{
    ll a = 1e18 - 1e8, b = 1e18;
    //scanf("%lld%lld", &a, &b);
    ll sum = 0;
    for (ll i = a; i <= b; ++i) {
        int suma = 0, sumb = 0;
        bool tag = 0;
        ll num = i;
        while (num) {
            if (tag) {
                suma += num % 10;
            } else {
                sumb += num % 10;
            }
            tag = !tag;
            num /= 10;
        }
        if (suma == sumb) {
            ++sum;
        }
    }
    printf("%lld\n", sum);
    return 0;
}
/*
811111881818118800000011000118107
*/