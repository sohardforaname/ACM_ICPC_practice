#include <deque>
#include <iostream>
using namespace std;
long long h[100005];
int res[100005];
long long ans = 0;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> h[i], res[i] = i + 1;
    h[n] = 1000000005;
    deque<int> que;
    for (int i = 0; i <= n; ++i) {
        while (!que.empty() && h[que.back()] <= h[i]) {
            res[que.back()] = i;
            que.pop_back();
        }
        que.push_back(i);
    }
    for (int i = 0; i < n; ++i)
        ans += (res[i] - i - 1);
    cout << ans << endl;
}