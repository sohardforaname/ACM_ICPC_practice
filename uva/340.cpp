#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
vector<int>sec_pos[9];
vector<int>gue_pos[9];
int buf[1005];
int main()
{
	int n, a, pos_t, pos_w, pos, index = 0;
	while (scanf("%d", &n) && n)
	{
		++index;
		for (int i = 0; i < 9; ++i)
			sec_pos[i].clear();
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &a);
			sec_pos[a - 1].push_back(i);
		}
		printf("Game %d:\n", index);
		while (scanf("%d", &buf[0]) && buf[0])
		{
			pos_t = 0, pos_w = 0;
			for (int i = 1; i < n; ++i)
				scanf("%d", &buf[i]);
			for (int i = 0; i < 9; ++i)
				gue_pos[i].clear();
			for (int i = 0; i < n; ++i)
				gue_pos[buf[i] - 1].push_back(i);
			for (int i = 0; i < 9; ++i)
			{
				pos = 0;
				int len_1 = sec_pos[i].size(), len_2 = gue_pos[i].size();
				int j_1 = 0, j_2 = 0;
				while (j_1 < len_1&&j_2 < len_2)
				{
					if (sec_pos[i][j_1] == gue_pos[i][j_2])
						++j_1, ++j_2, ++pos;
					else if (sec_pos[i][j_1] > gue_pos[i][j_2])
						++j_2;
					else if (sec_pos[i][j_1] < gue_pos[i][j_2])
						++j_1;
				}
				pos_w += min(len_1, len_2) - pos;
				pos_t += pos;
			}
			printf("    (%d,%d)\n", pos_t, pos_w);
		}
		for (int i = 1; i < n; ++i)
			scanf("%d", &buf[i]);
	}
	return 0;
}
/*int main()
{
	const char *p = "111.11 -2.22 Nan nan(2) inF 0X1.BC70A3D70A3D7P+6  1.18973e+4932zzz";
	printf("Parsing '%s':\n", p);
	char *end;
	double f;
	for (f = strtod(p, &end); p != end; f = strtod(p, &end))
	{
		printf("'%.*s' -> ", (int)(end - p), p);//I can't understand this line
		p = end;
		if (errno == ERANGE) {
			printf("range error, got ");
			errno = 0;
		}
		printf("%f\n", f);
	}
	return 0;
}*/