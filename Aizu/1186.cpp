#include <bits/stdc++.h>
using namespace std;
pair<int, int> p;
bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    return make_pair(a.first * a.first + a.second * a.second, a.first) <
           make_pair(b.first * b.first + b.second * b.second, b.first);
}
vector<pair<int, int>> v;
int main()
{
    for (int i = 1; i < 200; ++i)
        for (int j = i + 1; j <= 200; ++j)
            v.push_back({i, j});
    sort(v.begin(), v.end(), cmp);
    int h, w;
    while (scanf("%d%d", &h, &w) && (h + w))
    {
        pair<int, int> tmp = *(lower_bound(v.begin(), v.end(), make_pair(h, w), cmp) + 1);
        printf("%d %d\n", tmp.first, tmp.second);
    }
    return 0;
}