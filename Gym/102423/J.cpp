#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 4;
int a[N], cnt[N], in[N], pos[N], k, n;
deque<int> dq;
int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        cnt[a[i]]++;
    }
    for (int i = 1; i <= n; i++)
    {
        cnt[a[i]]--;
        if (in[a[i]] == 0)
        {
            in[a[i]] = 1;
            while (!dq.empty() && cnt[dq.front()] != 0 && dq.front() > a[i])
            {
                in[dq.front()] = 0;
                dq.pop_front();
            }
            dq.push_front(a[i]);
        }
    }
    while (!dq.empty())
    {
        printf("%d ", dq.back());
        dq.pop_back();
    }
    return 0;
}