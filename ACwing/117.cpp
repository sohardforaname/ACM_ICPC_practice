#include <bits/stdc++.h>
using namespace std;
struct Node
{
    char ch;
    bool tag;
    Node() {}
    Node(char _ch, bool _tag) : ch(_ch), tag(_tag) {}
};
deque<Node> que[15];
map<int, int> mp, summp;
void init()
{
    for (int i = 2; i <= 9; ++i)
        mp[i + '0'] = i;
    mp['0'] = 10, mp['J'] = 11;
    mp['Q'] = 12, mp['K'] = 13;
    mp['A'] = 1;
}
int main()
{
    init();
    char ch[2];
    for (int i = 1; i <= 13; ++i)
        for (int j = 1; j <= 4; ++j)
        {
            scanf("%s", ch);
            que[i].push_back(Node(ch[0], 0));
        }
    for (int i = 0; i < 4; ++i)
    {
        auto tmp = que[13].front();
        que[13].pop_front();
        while (tmp.ch != 'K')
        {
            int pos = mp[tmp.ch];
            tmp.tag = 1;
            //printf("%c\n",tmp.ch);
            que[pos].push_front(tmp);
            tmp = que[pos].back();
            que[pos].pop_back();
        }
    }
    for (int i = 1; i <= 13; ++i)
        while (!que[i].empty())
        {
            auto tmp = que[i].front();
            if (tmp.tag)
                ++summp[tmp.ch];
            que[i].pop_front();
        }
    int ans = 0;
    for (auto &i : summp)
        if (i.first != 'K' && i.second == 4)
            ++ans;
    printf("%d\n", ans);
    return 0;
}