#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
#define maxn int(1e6+9)
int trie[maxn][26];
int cntword[maxn];
int fail[maxn];
int cnt = 0, strid = 0;
struct stru
{
	int num, pos;
};
stru ans[200];
vector<string>input;
struct ac
{
	void insert(string& str)
	{
		int root = 0, next;
		for (int i = 0; i < str.size(); ++i)
		{
			next = str[i] - 'a';
			if (!trie[root][next])
				trie[root][next] = ++cnt;
			root = trie[root][next];
		}
		cntword[root] = ++strid;
	}
	void buildfail()
	{
		queue<int>que;
		for (int i = 0; i < 26; ++i)
			if (trie[0][i])
			{
				que.push(trie[0][i]);
				fail[trie[0][i]] = 0;
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
	void query(string& str)
	{
		int now = 0;
		for (int i = 0; i < str.size(); ++i)
		{
			now = trie[now][str[i] - 'a'];
			for (int j = now; j; j = fail[j])
				++ans[cntword[j]].num;
		}
	}
};
bool cmp(const stru &a,const stru &b)
{
	if (a.num == b.num)
		return a.pos < b.pos;
	return a.num > b.num;
}
int main()
{
	string tmp;
	ac a;
	int n;
	while (cin >> n && n)
	{
		memset(trie, 0, sizeof(trie));
		memset(fail, 0, sizeof(fail));
		memset(cntword, 0, sizeof(cntword));
		cnt = 0; strid = 0;
		input.clear();
		for (int i = 1; i <= n; ++i)
		{
			ans[i].num = 0;
			ans[i].pos = i;
			cin >> tmp;
			input.push_back(tmp);
			a.insert(tmp);
		}
		a.buildfail();
		cin >> tmp;
		a.query(tmp);
		sort(ans + 1, ans + n + 1, cmp);
		cout << ans[1].num << endl;
		for (int i = 1; ans[i].num /*== ans[1].num*/; ++i)
			cout << input[ans[i].pos - 1] << endl;
	}
	return 0;
}