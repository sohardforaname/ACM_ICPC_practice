#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 1e5 + 5;
const int MAXM = 55;
int hs[150];
int trie[MAXN][MAXM];
int a[MAXN];
int cnt = 0;
void init()
{
	for (int i = 2; i <= 9; ++i)
		hs[i + '0'] = i - 1;
	hs['A'] = hs['0'] = hs['C'] = 0;
	hs['J'] = 10, hs['Q'] = 11, hs['K'] = 12;
	hs['1'] = 9; 
	hs['D'] = 13;
	hs['H'] = 26;
	hs['S'] = 39;
}
bool isend(char ch)
{
	return ch == 'C' || ch == 'D' || ch == 'H' || ch == 'S';
}
void insert(int* a, int len)
{
	int root = 0;
	for (int i = len; i; --i)
	{
		if (!trie[root][a[i]])
			trie[root][a[i]] = ++cnt;
		root = trie[root][a[i]];
	}
}
char str[10];
int main()
{
	int n;
	init();
	while (scanf("%d", &n) && n)
	{
		memset(trie, 0, sizeof(trie));
		cnt = 0;
		int len;
		for (int i = 1; i <= n; ++i)
		{
			scanf("%d", &len);
			for (int j = 1; j <= len; ++j)
			{
				scanf("%s", str);
				int slen = strlen(str);
				for (int k = 0; k < slen; ++k)
					a[j] += hs[str[k]];
			}
			insert(a, len);
			for (int j = 1; j <= len; ++j)
				a[j] = 0;
		}
		printf("%d\n", cnt);
	}
	return 0;
}