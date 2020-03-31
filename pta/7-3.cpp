#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
struct bst
{
	char ch, left, right;
};
bst res[12], des[12], tmp[12];
bool cmp(bst &a, bst &b)
{
	return a.ch < b.ch;
}
void solve(bst *ans, int n)
{
	for (int i = 0; i < n; ++i)
	{
		ans[i].ch = tmp[i].ch;
		if (tmp[i].left != '-')
			ans[i].left = tmp[tmp[i].left - '0'].ch;
		else
			ans[i].left = '-';
		if (tmp[i].right != '-')
			ans[i].right = tmp[tmp[i].right - '0'].ch;
		else
			ans[i].right = '-';
	}
}
int main()
{
	int n;
	string stmp;
	cin >> n;
	getchar();
	for (int i = 0; i < n; ++i)
	{
		getline(cin, stmp);
		tmp[i].ch = stmp[0], tmp[i].left = stmp[2], tmp[i].right = stmp[4];
	}
	solve(res, n);
	sort(res, res + n, cmp);
	cin >> n;
	getchar();
	for (int i = 0; i < n; ++i)
	{
		getline(cin, stmp);
		tmp[i].ch = stmp[0], tmp[i].left = stmp[2], tmp[i].right = stmp[4];
	}
	solve(des, n);
	sort(des, des + n, cmp);
	bool flag = false;
	for (int i = 0; i < n; ++i)
	{
		if (res[i].left > res[i].right)
			swap(res[i].left, res[i].right);
		if (des[i].left > des[i].right)
			swap(des[i].left, des[i].right);
		if (res[i].ch != des[i].ch || res[i].left != des[i].left || res[i].right != des[i].right)
			flag = true;
	}
	if (flag)
		cout << "No" << endl;
	else
		cout << "Yes" << endl;
	return 0;
}