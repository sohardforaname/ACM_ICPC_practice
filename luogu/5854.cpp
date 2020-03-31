#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 5;
const int MAXBUF = 1 << 20;
char buf[1 << 20], * fh = NULL, * ft = NULL;
inline char gc()
{
	if (fh == ft)
	{
		int l = fread(buf, 1, MAXBUF, stdin);
		ft = (fh = buf) + l;
	}
	return *fh++;
}

inline int read()
{
	int x = 0;
	char c = gc();
	for (; c < '0' || c > '9'; c = gc())
		;
	for (; c >= '0' && c <= '9'; c = gc())
		x = (x << 3) + (x << 1) + c - '0';
	return x;
}
inline void _write(long long x)
{
	if (x > 9)
		_write(x / 10);
	putchar(x % 10 + '0');
}
inline void write(long long x)
{
	_write(x);
	putchar(' ');
}
struct node
{
	int son[2];
	int num;
};
node tr[N];
int s[N];
int main()
{
	int n;
	n = read();
	for (int i = 1; i <= n; ++i)
		tr[i].num = read();
	int top = 0;
	for (int i = 1; i <= n; ++i)
	{
		while (top && tr[s[top]].num > tr[i].num)//s.top比i小，则s.top在左子树
			tr[i].son[0] = s[top--];
		if (top)//s.top比i小，且值比num[i]小
			tr[s[top]].son[1] = i;
		s[++top] = i;
	}
	long long l = 0, r = 0;
	for (long long i = 1; i <= n; ++i)
	{
		l ^= i * (tr[i].son[0] + 1);
		r ^= i * (tr[i].son[1] + 1);
	}
	write(l);
	write(r);
	putchar('\n');
	return 0;
}