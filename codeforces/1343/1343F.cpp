#include <bits/stdc++.h>
using namespace std;
vector<set<int>> segs, cur;
vector<int> ans;
set<int> ins;
void init()
{
    segs.clear();
}
void solve()
{
    init();
    int n, cnt = 0;
    scanf("%d", &n);
    for (int i = 1; i < n; ++i)
    {
        ins.clear();
        cnt = 0;
        int a = 0;
        scanf("%d", &cnt);
        for (int j = 1; j <= cnt; ++j)
        {
            scanf("%d", &a);
            ins.insert(a);
        }
        segs.push_back(ins);
    }
    for (cnt = 1; cnt <= n; ++cnt)
    {
        ans.clear();
        ans.push_back(cnt);
        cur = segs;
        for (auto &s : cur)
            if (s.count(cnt))
                s.erase(cnt);
        bool flag = 1;
        for (int i = 1; i < n; ++i)
        {
            int cnt1 = 0;
            int nxt = -1;
            for (auto &s : cur)
                if (s.size() == 1)
                {
                    ++cnt1;
                    nxt = *s.begin();
                }
            if (cnt1 != 1)
            {
                flag = 0;
                break;
            }
            for (auto &s : cur)
                if (s.count(nxt))
                    s.erase(nxt);
            ans.push_back(nxt);
        }
        if (flag)
        {
            set<set<int>> chks(segs.begin(), segs.end());
            for (int i = 1; i < n; ++i)
            {
                ins.clear();
                ins.insert(ans[i]);
                bool f = 0;
                for (int j = i - 1; j >= 0; --j)
                {
                    ins.insert(ans[j]);
                    if (chks.count(ins))
                    {
                        chks.erase(ins);
                        f = 1;
                        break;
                    }
                }
                if (!f)
                    flag = 0;
            }
        }
        if (flag)
        {
            for (auto &i : ans)
                printf("%d ", i);
            printf("\n");
            break;
        }
    }
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}