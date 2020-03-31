#include <bits/stdc++.h>
using namespace std;
int rule[26][2], num[26], sum[300005][26];
string str, ans;
int main()
{
    int k;
    queue<int> que[26];
    while (cin >> str)
    {
        cin >> k;
        for (int i = 0; i < 26; ++i)
        {
            cin >> rule[i][0] >> rule[i][1];
            sum[str.size()][i] = 0;
            num[i] = 0;
            while (que[i].size())
                que[i].pop();
        }
        ans = "";
        for (int i = 0; i < str.size(); ++i)
            que[str[i] - 'a'].push(i);
        for (int i = str.size() - 1; i > -1; --i)
            for (int j = 0; j < 26; ++j)
                sum[i][j] = sum[i + 1][j] + ((str[i] - 'a') == j);
        int now = -1;
        bool isputok = 0, isgenok = 1;
        int chosen, anspos = 0;
        for (int i = 1; i <= k; ++i)
        {
            for (int j = 0; j < 26; ++j)
            {
                if (num[j] == rule[j][1])
                    continue;
                isputok = 1;
                while (!que[j].empty() && now >= que[j].front())
                    que[j].pop();
                if (!que[j].empty())
                {
                    ++num[j];
                    chosen = que[j].front();
                    for (int l = 0; l < 26; ++l)
                        if (num[l] + sum[chosen + 1][l] < rule[l][0])
                        {
                            isputok = 0;
                            --num[j];
                            break;
                        }
                    int minn = 0, maxn = 0;
                    if (isputok)
                    {
                        for (int l = 0; l < 26; ++l)
                        {
                            minn += max(rule[l][0] - num[l], 0);
                            maxn += min(rule[l][1], sum[chosen + 1][l]);
                        }
                        if (minn + i <= k && maxn + i >= k)
                        {
                            ans += char(j + 'a');
                            now = chosen;
                            ++anspos;
                            break;
                        }
                        else
                            --num[j];
                    }
                }
            }
            if (anspos != i)
            {
                isgenok = 0;
                break;
            }
        }
        if (isgenok)
            cout << ans << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}
