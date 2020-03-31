#include <iostream>
#include <string>
#include <queue>
using namespace std;
#define maxn int(2e6+5)
int trie[maxn][26];
int cntword[maxn];
int fail[maxn];
int cnt = 0;
struct ac
{
	void insert(string& str)//插入字符串
	{
		int root = 0, next;
		for (int i = 0; i < str.size(); ++i)
		{
			next = str[i] - 'a';
			if (!trie[root][next])
				trie[root][next] = ++cnt;//将字符的位置按照放入顺序递增
			root = trie[root][next];
		}
		++cntword[root];//该位置单词结束
	}
	void buildfail()
	{
		queue<int>que;
		for (int i = 0; i < 26; ++i)
		{
			if (trie[0][i])
			{
				fail[trie[0][i]] = 0;//根的儿子的fail一定指向根
				que.push(trie[0][i]);//将其放入队列
			}
		}
		while (!que.empty())
		{
			int now = que.front();//出队，以其为根
			que.pop();
			for (int i = 0; i < 26; ++i)
			{
				if (trie[now][i])
				{
					fail[trie[now][i]] = trie[fail[now]][i];//fail指向其父节点的fail对应的相同子节点
					que.push(trie[now][i]);
				}
				else
					trie[now][i] = trie[fail[now]][i];//空节点是其父节点对应fail的相同儿子
			}
		}
	}
	int query(string& str)
	{
		int now = 0, ans = 0;
		for (int i = 0; i < str.size(); ++i)
		{
			now = trie[now][str[i] - 'a'];
			for (int j = now; j && cntword[j] != -1; j = fail[j])//匹配根到当前结点的子串的后缀以节省时间
			{
				ans += cntword[j];
				cntword[j] = -1;
			}
		}
		return ans;
	}
};
int main()
{
	string tmp;
	ios::sync_with_stdio(0);
	cin.tie(0);
	ac AC;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> tmp;
		AC.insert(tmp);
	}
	fail[0] = 0;
	cin >> tmp;
	AC.buildfail();
	cout << AC.query(tmp) << endl;
	return 0;
}