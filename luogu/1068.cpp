#include <iostream>
#include <algorithm>
using namespace std;
struct node
{
	int index, grade;
}num[5005];
bool cmp(node& a, node& b)
{
	if (a.grade == b.grade)
		return a.index < b.index;
	return a.grade > b.grade;
}
int main()
{
	int n, m;
	cin >> n >> m;
	m *= 1.5;
	for (int i = 0; i < n; ++i)
		cin >> num[i].index >> num[i].grade;
	sort(num, num + n, cmp);
	int lim = num[m - 1].grade, pos = m;
	while (pos < n && num[pos].grade == lim)
		++pos;
	cout << lim << " " << pos << endl;
	for (int i = 0; i < pos; ++i)
		cout << num[i].index << " " << num[i].grade << endl;
	return 0;
}