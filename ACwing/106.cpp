#include <bits/stdc++.h>
#pragma GCC optimize(3)
using namespace std;
priority_queue<int> bque;
priority_queue<int, vector<int>, greater<int>> sque;
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        while (bque.size())
            bque.pop();
        while (sque.size())
            sque.pop();
        int index, n, a;
        scanf("%d%d", &index, &n);
        printf("%d %d\n", index, (n + 1) >> 1);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a);
            if (bque.empty() || a <= bque.top())
                bque.push(a);
            else if (a > bque.top())
                sque.push(a);
            if (i % 2) {
                while (bque.size() > sque.size() + 1)
                    sque.push(bque.top()), bque.pop();
                while (sque.size() > bque.size() - 1)
                    bque.push(sque.top()), sque.pop();
                printf("%d%c", bque.top(), i == n || (i + 1) % 20 == 0 ? '\n' : ' ');
            }
        }
    }
    return 0;
}
