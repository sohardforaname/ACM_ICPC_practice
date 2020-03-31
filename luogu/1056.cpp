#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct node
{
	int num, index;
}t1[1005], t2[1005];
bool cmp(node& a, node& b)
{
	if (a.num == b.num)
		return a.index < b.index;
	return a.num > b.num;
}
int main()
{
	int a, b, c, d;
	int n, m, k, l, dd;
	cin >> m >> n >> k >> l >> dd;
	for (int i = 1; i < 1005; ++i)
	{
		t1[i].index = i;
		t2[i].index = i;
	}
	for (int i = 0; i < dd; ++i)
	{
		cin >> a >> b >> c >> d;
		if (a == c)//ºá×Å
			++t1[min(b, d)].num;
		else if (b == d)//Êú×Å
			++t2[min(a, c)].num;
	}
	sort(t1 + 1, t1 + n + 1, cmp);
	sort(t2 + 1, t2 + m + 1, cmp);
	vector<int>ans1, ans2;
	for (int i = 1; i <= k; ++i)
		ans1.push_back(t2[i].index);
	sort(ans1.begin(), ans1.end());
	for (int i = 0; i < ans1.size(); ++i)
	{
		cout << ans1[i];
		if (i < ans1.size() - 1)
			cout << " ";
		else
			cout << endl;
	}
	for (int i = 1; i <= l; ++i)
		ans2.push_back(t1[i].index);
	sort(ans2.begin(), ans2.end());
	for (int i = 0; i < ans2.size(); ++i)
	{
		cout << ans2[i];
		if (i < ans2.size() - 1)
			cout << " ";
		else
			cout << endl;
	}
	return 0;
}