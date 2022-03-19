#include <map>
#include <cstdio>
#include <cstring>
using namespace std;
struct Mat
{
    int m[2][2];
    Mat()
    {
        memset(m, 0, sizeof(m));
    }
};
const int mod = 9901;
Mat mul(const Mat a, const Mat b)
{
    Mat res;
    res.m[0][0] = (a.m[0][0] * b.m[0][0] + a.m[0][1] * b.m[1][0]) % mod;
    res.m[0][1] = (a.m[0][0] * b.m[0][1] + a.m[0][1] * b.m[1][1]) % mod;
    res.m[1][0] = (a.m[1][0] * b.m[0][0] + a.m[1][1] * b.m[1][0]) % mod;
    res.m[1][1] = (a.m[1][0] * b.m[0][1] + a.m[1][1] * b.m[1][1]) % mod;
    return res;
}
Mat pow(Mat a, long long b, int p)
{
    Mat res;
    res.m[0][0] = res.m[1][1] = 1;
    while (b)
    {
        if (b & 1)
            res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}
map<int, int> mp;
void get_pri(int n)
{
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0)
            while (n % i == 0)
            {
                n /= i;
                ++mp[i];
            }
    ++mp[n];
}
int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    get_pri(a);
    int ans = 0;
    for (map<int, int>::iterator it = mp.begin(); it != mp.end(); ++it)
    {
        Mat pp;
        pp.m[0][1] = 1 + it->first;
        pp.m[1][1] = 1;
        Mat tmp;
        tmp.m[0][0] = it->first;
        tmp.m[0][1] = tmp.m[1][1] = 1;
        tmp = pow(tmp, (it->second) * b, mod);
        tmp = mul(tmp, pp);
        ans = ans * tmp.m[0][1] % mod;
    }
    printf("%d\n", ans);
    return 0;
}