// AC自动机.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//fail树和Trie图优化进行中
#include "pch.h"
#include <iostream>
#include "string"
#include <queue>
#include <cctype>
using namespace std;
using std::queue;
struct Trienode
{
	int isend;
	Trienode *fail;
	Trienode *alpha[26];
};
Trienode *getroot();
Trienode *insert(Trienode *trie, string node);
int find(Trienode *trie, string str);
void buildACautomation(Trienode *trie);
string pipei(Trienode *trie, string str);
void forder(Trienode *root);
int main()
{
	int n, k;
	cin >> n;
	string str;
	while (n--)
	{
		Trienode *root = getroot();
		cin >> k;
		while (k--)
		{
			cin >> str;
			root = insert(root, str);
		}
		getchar();
		buildACautomation(root);
		getline(cin, str);
		str = pipei(root, str);
		cout << str;
		cout << endl;
		forder(root);
	}
	//forder(root);
	return 0;
}
Trienode *getroot()
{
	Trienode *root = new Trienode{false, NULL, {NULL}};
	root->fail = root;
	return root;
}
Trienode *insert(Trienode *root, string str)
{
	Trienode *p = root;
	int i = 0;
	while (i < str.size())
	{
		if (p->alpha[str[i] - 'a'] == NULL) //加入节点
		{
			Trienode *node = new Trienode{false, NULL, {NULL}};
			p->alpha[str[i] - 'a'] = node;
		}
		p = p->alpha[str[i] - 'a'];
		if (i == str.size() - 1)
		{
			p->isend = str.size();
		}
		++i;
	}
	return root;
}
int find(Trienode *trie, string str)
{
	int val = 0, i = 0;
	while (i < str.size())
	{
		if (trie->alpha[str[i] - 'a'] == NULL)
		{
			val = 0;
			break;
		}
		else
		{
			trie = trie->alpha[str[i] - 'a'];
		}
		++i;
	}
	return val;
}
void forder(Trienode *root)
{
	for (int i = 0; i != 26; ++i)
		if (root->alpha[i] != NULL)
			forder(root->alpha[i]);
	delete root;
}
void buildACautomation(Trienode *trie)
{
	queue<Trienode *> bfs;
	bfs.push(trie);
	Trienode *root = trie;
	Trienode *nownode;
	Trienode *tmp;
	while (!bfs.empty())
	{
		nownode = bfs.front();
		bfs.pop();
		for (int i = 0; i != 26; ++i)
		{
			if (nownode->alpha[i] != NULL)
			{
				if (nownode == root)
					nownode->alpha[i]->fail = root;
				else
				{
					tmp = nownode->fail;
					if (tmp->alpha[i] != NULL)
						nownode->alpha[i]->fail = tmp->alpha[i];
					else
						nownode->alpha[i]->fail = root;
				}
				bfs.push(nownode->alpha[i]);
			}
		}
	}
}
string pipei(Trienode *trie, string str)
{
	int i = 0, l = str.size();
	Trienode *p = trie;
	string recodestr = "";
	Trienode *root = trie;
	bool flag = 0;
	while (i < l)
	{
		if (!isalpha(str[i]))
		{
			recodestr += str[i];
			++i;
			flag = 0;
			continue;
		}
		if (isupper(str[i]))
		{
			str[i] = tolower(str[i]);
			flag = 1;
		}
		if (p->alpha[str[i] - 'a'] != NULL)
		{
			if (flag)
				recodestr += toupper(str[i]);
			else
				recodestr += str[i];
			//recodestr[recodestr.size() - 1] = '*';
			p = p->alpha[str[i] - 'a'];
			if (p->isend)
			{
				for (int x = i; x > i - p->isend; --x)
				{
					recodestr[x] = '*';
				}
			}
			//cout << i + 1 << endl;
			++i;
			flag = 0;
		}
		else if (p == trie)
		{
			if (flag)
				recodestr += toupper(str[i]);
			else
				recodestr += str[i];
			++i;
			flag = 0;
		}
		else
		{
			p = p->fail;
		}
	}
	return recodestr;
}