#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
using namespace std;
#define maxn int(1e5 + 9)
int trie[maxn][26], fail[maxn], cntword[maxn], cnt = 0, strid = 0;
int ex[maxn];
struct AC
{
	void insert(string &str)
	{
		int root = 0, next;
		for (int i = 0; i < str.size(); ++i)
		{
			next = str[i] - 'a';
			if (!trie[root][next])
				trie[root][next] = ++cnt;
			root = trie[root][next];
		}
		cntword[root] = str.size();
	}
	void buildfail()
	{
		queue<int> que;
		for (int i = 0; i < 26; ++i)
		{
			if (trie[0][i])
			{
				fail[trie[0][i]] = 0;
				que.push(trie[0][i]);
			}
		}
		while (!que.empty())
		{
			int now = que.front();
			que.pop();
			for (int i = 0; i < 26; ++i)
			{
				if (trie[now][i])
				{
					fail[trie[now][i]] = trie[fail[now]][i];
					que.push(trie[now][i]);
				}
				else
					trie[now][i] = trie[fail[now]][i];
			}
		}
	}
	void query(string &str)
	{
		int now = 0, ans = 0;
		for (int i = 0; i < str.size(); ++i)
		{
			now = trie[now][str[i] - 'a'];
			for (int j = now; j; j = fail[j])
			{
				if (!ex[i])
					ex[i] = cntword[j];
			}
		}
	}
};
int main()
{
	string que, tmp;
	int n;
	cin >> que >> n;
	AC ac;
	for (int i = 0; i < n; ++i)
	{
		cin >> tmp;
		ac.insert(tmp);
	}
	ac.buildfail();
	ac.query(que);
	for (int i = 0; i < que.size(); ++i)
		cout << ex[i] << endl;
	int left = 0;
	for (int i = que.size() - 1; i >= 0; --i)
	{
		if (!ex[i] && left)
		{
			ex[i] = 1;
			--left;
		}
		else if (ex[i])
		{
			left += ex[i];
			ex[i] = 1;
			--left;
		}
	}
	for (int i = 0; i < que.size(); ++i)
		if (!ex[i])
			cout << que[i];
	cout << endl;
	return 0;
}