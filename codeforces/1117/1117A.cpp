#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
struct node
{
	int k;
	int times;
};
node N[100005];
bool cmp1(node &A, node &B)
{
	if (A.k == B.k)
		return A.times < B.times;
	return A.k < B.k;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int tmp, k = 1, cmp;
	cin >> cmp;
	int pos = 0;
	for (int i = 1; i < n; ++i)
	{
		cin >> tmp;
		if (tmp == cmp)
			++k;
		else
		{
			N[pos].k = cmp, N[pos++].times = k;
			k = 1;
			cmp = tmp;
		}
	}
	N[pos].k = cmp, N[pos++].times = k;
	sort(N, N + pos, cmp1);
	cout << N[pos - 1].times << endl;
	return 0;
}