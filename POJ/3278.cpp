#include <iostream>
#include <queue>
using namespace std;
int e, s;
bool vis[200005];
void bfs()
{
    int dep;
    queue<pair<int, int>> que;
    que.push(make_pair(s, 1));
    while (!que.empty()) {
        int u = que.front().first;
        dep = que.front().second;
        que.pop();
        //cout<<u<<" "<<dep<<endl;
        if (vis[u] || u < 0)
            continue;
        vis[u] = 1;
        if (u > e) {
            if (!vis[u - 1])
                que.push(make_pair(u - 1, dep + 1));
        } else if (u < e) {
            if (!vis[u + 1])
                que.push(make_pair(u + 1, dep + 1));
            if (!vis[u - 1])
                que.push(make_pair(u - 1, dep + 1));
            if (!vis[u * 2])
                que.push(make_pair(u * 2, dep + 1));
        } else
            break;
    }
    cout << dep - 1 << endl;
}
int main()
{
    cin >> s >> e;
    bfs();
    return 0;
}
