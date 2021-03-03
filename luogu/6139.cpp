#include "../base.h"

bool multi = 0;
const int N = 2e6 + 5;

struct SAM {
    int cnt, link[N], maxl[N], trans[N][26];

private:
    int func(int p, int x, char c)
    {
        int y = ++cnt;
        maxl[y] = maxl[p] + 1;
        memcpy(trans[y], trans[x], sizeof(trans[x]));
        while (p && trans[p][c] == x)
            trans[p][c] = y, p = link[p];
        link[y] = link[x];
        link[x] = y;
        return y;
    }
    int insert(char c, int lst)
    {
        c -= 'a';
        if (trans[lst][c]) {
            int p = lst, x = trans[p][c];
            if (maxl[p] + 1 == maxl[x])
                return x;
            else
                return func(p, x, c);
        }
        int z = ++cnt, p = lst;
        maxl[z] = maxl[lst] + 1;
        while (p && !trans[p][c])
            trans[p][c] = z, p = link[p];
        int x = trans[p][c];
        if (!p)
            link[z] = 1;
        else if (maxl[p] + 1 == maxl[x])
            link[z] = x;
        else
            link[z] = func(p, x, c);
        return z;
    }

public:
    SAM()
        : cnt(1)
    {
    }
    void insert_str(const char* s)
    {
        int lst = 1;
        for (int i = 1; s[i]; ++i)
            lst = insert(s[i], lst);
    }
    ll cal()
    {
        ll ans = 0;
        for (int i = 2; i <= cnt; ++i)
            ans += maxl[i] - maxl[link[i]];
        return ans;
    }
};

char s[N];
SAM sam;
void solve()
{
    int n;
    io(n);
    for (int i = 1; i <= n; ++i) {
        io(s + 1);
        sam.insert_str(s);
    }
    io(sam.cal(), '\n');
}

MAIN_FUNC