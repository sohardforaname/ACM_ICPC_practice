#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
const int MAXM = 26;
struct SAM
{
	int maxlen[MAXN], link[MAXN], size, last;
	int nxt[MAXN][MAXM];
	SAM() :size(1), last(1) {}
	void extend(int ch)
	{
		ch -= 'a';
		int cur = (++size), p;
		maxlen[cur] = maxlen[last] + 1;
		for (p = last; p && !nxt[p][ch]; p = link[p])
			nxt[p][ch] = cur;
		if (!p)
			link[cur] = 1;
		else
		{
			int q = nxt[p][ch];
			if (maxlen[q] == maxlen[p] + 1)
				link[cur] = q;
			else
			{
				int tmp = ++size;
				maxlen[tmp] = maxlen[p] + 1;
				for (int i = 0; i < MAXM; ++i)
					nxt[tmp][i] = nxt[q][i];
				link[tmp] = link[q];
				for (; p && nxt[p][ch] == q; p = link[p])
					nxt[p][ch] = tmp;
				link[cur] = link[q] = tmp;
			}
		}
		last = cur;
	}
};