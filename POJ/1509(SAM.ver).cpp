#include <cstdio>
#include <cstring>
using namespace std;
const int N = 4e4 + 5;
const int M = 26;
struct SAM
{
    int nxt[N][M], link[N], maxl[N];
    int last, size, root;
    SAM() {}
    void init()
    {
        memset(nxt, 0, sizeof(nxt));
        memset(link, 0, sizeof(link));
        memset(maxl, 0, sizeof(maxl));
        last = size = root = 1;
    }
    void extend(int ch)
    {
        ch -= 'a';
        int cur = ++size, p;
        for (p = last; p && !nxt[p][ch]; p = link[p])
            nxt[p][ch] = cur;
        maxl[cur] = maxl[last] + 1;
        if (!p)
            link[cur] = root;
        else
        {
            int q = nxt[p][ch];
            if (maxl[q] == maxl[p] + 1)
                link[cur] = q;
            else
            {
                int tmp = ++size;
                maxl[tmp] = maxl[p] + 1;
                for (int i = 0; i < M; ++i)
                    nxt[tmp][i] = nxt[q][i];
                link[tmp] = link[q];
                for (; nxt[p][ch] == q; p = link[p])
                    nxt[p][ch] = tmp;
                link[q] = link[cur] = tmp;
            }
        }
        last = cur;
    }
    int get_ans(char *s, int n)
    {
        int now = root, ans = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < 26; ++j)
                if (nxt[now][j])
                {
                    ans = now = nxt[now][j];
                    break;
                }
        return maxl[ans] - n + 1;
    }
};
SAM sam;
char s[N];
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        sam.init();
        scanf("%s", s);
        for (int j = 1; j <= 2; ++j)
            for (int i = 0; s[i]; ++i)
                sam.extend(s[i]);
        printf("%d\n", sam.get_ans(s, strlen(s)));
    }
    return 0;
}