#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
#define maxn 200005
int trie[maxn][130], fail[maxn], cntword[maxn], cnt = 0, strid = 0;
bool strext[505], flag;
struct AC
{
	void insert(string &str)
	{
		int next, root = 0;
		for (int i = 0; i < str.size(); ++i)
		{
			next = str[i];
			if (!trie[root][next])
				trie[root][next] = ++cnt;
			root = trie[root][next];
		}
		cntword[root] = ++strid;
	}
	void buildfail()
	{
		queue<int> que;
		for (int i = 0; i < 130; ++i)
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
			for (int i = 0; i < 130; ++i)
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
		flag = 0;
		int ans = 0, now = 0;
		for (int i = 0; i < str.size(); ++i)
		{
			now = trie[now][str[i]];
			for (int j = now; j; j = fail[j])
			{
				//cout<<cntword[j]<<endl;
				strext[cntword[j]] = 1;
			}
		}
	}
};
int main()
{
	ios::sync_with_stdio(0);
	string tmp;
	int n;
	cin >> n;
	AC ac;
	for (int i = 0; i < n; ++i)
	{
		cin >> tmp;
		ac.insert(tmp);
	}
	ac.buildfail();
	int m;
	cin >> m;
	int tot = 0;
	for (int i = 0; i < m; ++i)
	{
		cin >> tmp;
		memset(strext, 0, sizeof(strext));
		ac.query(tmp);
		for (int j = 1; j <= n; ++j)
		{
			//cout<<strext[j]<<endl;
			if (strext[j])
			{
				if (!flag)
				{
					cout << "web " << i + 1 << ":";
					flag = 1;
				}
				cout << " " << j;
			}
		}
		if (flag)
		{
			++tot;
			cout << endl;
		}
	}
	cout << "total: " << tot << endl;
	return 0;
}
