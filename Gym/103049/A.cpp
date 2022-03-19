#include <bits/stdc++.h>
//#pragma GCC optimize(2)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define min(x, y) ((x) > (y) ? (y) : (x))
#define max(x, y) ((x) < (y) ? (y) : (x))
#define abs(x) ((x) < 0 ? ((-1) * (x)) : (x))
#define set0(x) (memset((x), 0, sizeof(x)))
#define rep(i, start, end) for (int i = (start); i <= (end); i++)
#define usecin                        \
    std::ios::sync_with_stdio(false); \
    std::cin.tie(0)
const int inf = 0x3f3f3f3f;
const ll INF = 0xffffffffffffff;

const int N = 1e2 + 5;
const int M = 5e6 + 5;
const int DP_SIZE = 1e5;
const ll mod = 998244353;

int a[N], b[N];
ll dp[M];

int main()
{
    //freopen("C:/Users/dell/Desktop/in.txt","r+",stdin);
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
    }
    for (int j = 1; j < M; ++j) {
        dp[j] = 2e18;
    }
    dp[0] = 0;

    for (int i = 1; i <= n; ++i) {
        dp[i] = a[i];
    }
    for (int i = n + 1; i <= DP_SIZE; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i] = min(dp[i], dp[i - j] + a[j]);
        }
    }
    // for (int i = 1; i <= n; ++i) {
    //     for (int j = n + 1; j <= DP_SIZE; ++j) {
    //         dp[j] = min(dp[j], dp[j - i] + a[i]);
    //     }
    // }
    for (int i = 1; i <= q; ++i) {
        int k;
        scanf("%d", &k);
        if (k <= DP_SIZE) {
            printf("%lld\n", dp[k]);
            continue;
        }
        ll minn = LLONG_MAX;
        for (int j = 1; j <= n; ++j) {
            int tmp = (k - DP_SIZE) / j + ((k - DP_SIZE) % j != 0);
            int res = k - tmp * j;
            minn = min(minn, 1ll * tmp * a[j] + dp[res]);

            // int rem = DP_SIZE + ((k - DP_SIZE) % j) - j;
            // ll Q = (k - rem) / j;
            // minn = min(a[j] * Q + dp[rem], minn);
        }
        printf("%lld\n", minn);
    }
    system("pause");
    return 0;
}