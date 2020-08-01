#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 5;
unordered_map<long long, int> mp;
pair<int, int> p[N];
pair<int, int> operator-(const pair<int, int> &a, const pair<int, int> &b)
{
    return make_pair(a.first - b.first, a.second - b.second);
}
double dist(const pair<int, int> &vec)
{
    return sqrt(vec.first * vec.first + vec.second * vec.second);
}
double dotcos(const pair<int, int> &a, const pair<int, int> &b)
{
    return (a.first * b.first + a.second * b.second) / (dist(a) * dist(b));
}
int cross(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.first * b.second - b.first * a.second;
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &p[i].first, &p[i].second);
    int maxn = 0;
    for (int i = 1; i <= n; ++i)
    {
        mp.clear();
        for (int j = 1; j <= n; ++j)
            if (cross(p[i], p[j]) < 0)
                ++mp[dotcos(p[j] - make_pair(0, 0), p[j] - p[i]) * 1e14];
        for (auto &j : mp)
            maxn = max(maxn, j.second);
    }
    printf("%d\n", maxn + 1);
    return 0;
}