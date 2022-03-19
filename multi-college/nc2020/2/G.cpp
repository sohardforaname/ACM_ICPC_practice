#include <bits/stdc++.h>
using namespace std;
const int N = 1.5e5 + 5;
bitset<N> f, g;
struct node
{
    int val, id;
};
node a[N], b[N];
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i].val), a[i].id = i;
    for (int i = 1; i <= m; ++i)
        scanf("%d", &b[i].val), b[i].id = i;
    sort(a + 1, a + n + 1, [](const node &a, const node &b) -> bool { return a.val > b.val; });
    sort(b + 1, b + m + 1, [](const node &a, const node &b) -> bool { return a.val > b.val; });
    f.set();
    g.reset();
    for (int i = 1, j = 1; i <= m; ++i)
    {
        while (j <= n && a[j].val >= b[i].val)
            g.set(a[j++].id);
        //cout << "g=" << g << endl;
        f &= g >> b[i].id;
        //cout << "f=" << f << endl;
    }
    printf("%d\n", f.count());
    return 0;
}