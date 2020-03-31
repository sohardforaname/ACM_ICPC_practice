#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 1.6e7 + 5;
char s[MAXN];
bool num[MAXN];
int hs[MAXN];
int tag[150];
int main()
{
	int n, m;
	while (~scanf("%d%d",&n, &m))
	{
		scanf("%s", s + 1);
		int len = strlen(s + 1);
		int cnt = 0, ans = 0;
		for (int i = 1; i <= len; ++i)
		{
			if (!tag[s[i]])
				tag[s[i]] = cnt++;
			if (cnt == m)
				break;
		}
		for (int i = 1; i <= len - n + 1; ++i)
		{
			int sum = 0;
			for (int j = i; j < i + n; ++j)
				sum = sum * m + tag[s[j]];
			if (!num[sum])
				++ans, num[sum] = 1;
		}
		printf("%d\n", ans);
	}
	return 0;
}