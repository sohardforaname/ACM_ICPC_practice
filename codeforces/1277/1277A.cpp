#include <bits/stdc++.h>
using namespace std;
int num[15];
vector<int>v;
int main()
{
	num[1] = 1;
	for (int i = 2; i <= 9; ++i)
		num[i] = num[i - 1] * 10 + 1;
	for (int i = 1; i <= 9; ++i)
		for (int j = 1; j <= 9; ++j)
			v.push_back(num[i] * j);
	int t, a;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &a);
		printf("%d\n", upper_bound(v.begin(), v.end(), a) - v.begin());
	}
	return 0;
}