#include <iostream>
using namespace std;
int num[15], tmp[15], sorted[15];
struct bst
{
	int val;
	bst *left;
	bst *right;
};
bst *insert(bst *root, int val)
{
	bst *tmp = new bst{val, NULL, NULL};
	bst *p = root, *pre = NULL;
	while (p)
	{
		if (val < p->val)
			pre = p, p = p->left;
		else if (val > p->val)
			pre = p, p = p->right;
	}
	p = tmp;
	if (pre != NULL)
	{
		if (pre->val > p->val)
			pre->left = p;
		else
			pre->right = p;
	}
	return root;
}
int main()
{
	int n, m;
	cin >> n >> m;
	bst *res = NULL, *des = NULL;
	for (int i = 0; i < n; ++i)
	{
		cin >> num[i];
		res = insert(res, num[i]);
	}
	bool flag;
	for (int i = 0; i < m; ++i)
	{
		flag = 0;
		for (int j = 0; j < n; ++j)
		{
			cin >> tmp[j];
			if (tmp[j] != num[j])
				flag = 1;
		}
		if (!flag)
			continue;
		for (int j = 0; j < n; ++j)
			des = insert(des, tmp[j]);
	}
}