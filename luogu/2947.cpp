#include <deque>
#include <iostream>
using namespace std;
struct node
{
	int h, pos;
	node(int a, int b)
	{
		h = a, pos = b;
	}
};
int h[100005], ord[100005];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> h[i];
	deque<node> que;
	for (int i = 0; i < n; ++i)
	{
		while (!que.empty() && que.back().h < h[i])
		{
			ord[que.back().pos] = i;
			que.pop_back();
		}
		que.push_back(node(h[i], i));
	}
	while (!que.empty())
	{
		ord[que.back().pos] = -1;
		que.pop_back();
	}
	for (int i = 0; i < n; ++i)
		cout << ord[i] + 1 << endl;
	return 0;
}