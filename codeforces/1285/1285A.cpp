#include <bits/stdc++.h>
using namespace std;
char ch[100005];
int main()
{
	int n, l = 0, r = 0;
	scanf("%d", &n);
	scanf("%s", ch);
	for (int i = 0; i < n; ++i)
		ch[i] == 'L' ? ++l : ++r;
	printf("%d", l + r + 1);
	return 0;
}