#include <cstdio>
#include <cstring>
#include <cctype>
#include <map>
using namespace std;
int main() 
{
	map<char, double>m;
	m['C'] = 12.010, m['H'] = 1.008, m['O'] = 16.00, m['N'] = 14.01;
	char s[105];
	int n;
	scanf("%d", &n);
	while (n--) 
	{
		scanf("%s", s);
		double ans = 0;
		int len = strlen(s);
		for (int i = 0; i < len; ++i) 
		{
			if (isalpha(s[i]))
			{
				if (s[i + 1] == 0 || isalpha(s[i + 1]))
					ans += m[s[i]];
				else
				{
					int a;
					sscanf(s + i + 1, "%d", &a);
					ans += m[s[i]] * a;
				}
			}
		}
		printf("%.3lf\n", ans);
	}
	return 0;
}