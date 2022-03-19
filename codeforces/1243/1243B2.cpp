#include <bits/stdc++.h>
using namespace std;
const int MAXN = 55;
char str1[MAXN], str2[MAXN];
queue<pair<int, int> >q;
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		while (q.size())
			q.pop();
		int n;
		scanf("%d", &n);
		scanf("%s%s", str1 + 1, str2 + 1);
		bool f = 1;
		for (int i = 1; i < n; ++i)
		{
			if (str1[i] != str2[i])
			{
				bool fi = 0;
				for (int j = i + 1; j <= n; ++j)\
                {
					if (str2[i] == str2[j])
					{
						fi = 1;
						q.push(make_pair(i, j));
						swap(str1[i], str2[j]);
						break;
					}
					if (str2[i] == str1[j])
					{
						fi = 1;
						q.push(make_pair(j, j));
						q.push(make_pair(i, j));
						str1[j] = str2[j];
						str2[j] = str1[i];
						str1[i] = str2[i];
						break;
					}
                }
				if (!fi)
				{
					f = 0;
					break;
				}
			}
		}
		if (str1[n] != str2[n])
			f = 0;
		if (f)
		{
			printf("YES\n");
			printf("%d\n", q.size());
			while (!q.empty())
				printf("%d %d\n", q.front().first, q.front().second), q.pop();
		}
		else
			printf("NO\n");
	}
}