#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
char ch[N];
char ans[N];
int main()
{
	int m;
	while (~scanf("%s%d", ch, &m))
	{
		int len = strlen(ch);
		int pos = 0, top = 0;
		for (int i = 0; i < len - m; ++i)
		{
			int minn = 60, minpos = pos;
			for (int j = pos; j < i + m + 1; ++j)
				if (minn > ch[j])
					minn = ch[j], minpos = j;
			ans[++top] = minn;
			pos = minpos + 1;
		}
		bool zflag = 0;
		for (int i = 1; i <= top; ++i)
		{
			if (!zflag && ans[i] - '0')
				printf("%c", ans[i]), zflag = 1;
			else if (zflag)
				printf("%c", ans[i]);
		}
		if (!zflag)
			printf("0");
		printf("\n");
	}
	return 0;
}