#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int trie[N][26];
int cntword[N];
int cnt;
void insert(char* str, int len)
{
	int root = 0;
	for (int i = 0; i < len; ++i)
	{
		int nxt = str[i] - 'a';
		if (!trie[root][nxt])
			trie[root][nxt] = ++cnt;
		root = trie[root][nxt];
		++cntword[root];
	}
}
int check(char* str, int len)
{
	int root = 0;
	for (int i = 0; i < len; ++i)
	{
		int nxt = str[i] - 'a';
		root = trie[root][nxt];
		if (!root)
			return 0;
	}
	return cntword[root];
}
char str[1005];
int main()
{
	while (strcmp(gets(str),""))
		insert(str, strlen(str));
	while (~scanf("%s", str))
		printf("%d\n", check(str, strlen(str)));
	return 0;
}