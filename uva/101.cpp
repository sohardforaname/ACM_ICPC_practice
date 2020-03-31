#include <bits/stdc++.h>
using namespace std;
const int MAXN = 35;
vector<int>P[MAXN];
int n;
void findblock(int& p, int& h, int gal)
{
	for (p = 0; p < n; ++p)
		for (h = 0; h < P[p].size(); ++h)
			if (gal == P[p][h])
				return;
}
void pclear(int p, int h)
{
	for (int i = P[p].size() - 1; i > h; --i)
		P[P[p][i]].push_back(P[p][i]);
	P[p].resize(h + 1);
}
void move(int p1, int h1, int p2)
{
	for (int i = h1; i < P[p1].size(); ++i)
		P[p2].push_back(P[p1][i]);
	P[p1].resize(h1);
}
void print()
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d:", i);
		for (int j = 0; j < P[i].size(); ++j)
			printf(" %d", P[i][j]);
		putchar('\n');
	}
}
int main()
{
	string str1, o;
	int a, b;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		P[i].push_back(i);
	while (cin >> str1 && str1 != "quit")
	{
		cin >> a >> o >> b;
		int p1, h1, p2, h2;
		findblock(p1, h1, a);
		findblock(p2, h2, b);
		if (p1 == p2)
			continue;
		if (o == "onto")
			pclear(p2, h2);
		if (str1 == "move")
			pclear(p1, h1);
		move(p1, h1, p2);
	}
	print();
	return 0;
}
