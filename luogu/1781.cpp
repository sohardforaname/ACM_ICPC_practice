#include <iostream>
#include <algorithm>
using namespace std;
struct node
{
	int index;
	string str;
}p[25];
bool cmp(node& a, node& b)
{
	if (a.str.size() == b.str.size())
		return a.str > b.str;
	return a.str.size() > b.str.size()
}
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> p[i].str;
		p[i].index = i + 1;
	}
	sort(p, p + n, cmp);
	cout << p[0].index << endl << p[0].str << endl;
	return 0;
}