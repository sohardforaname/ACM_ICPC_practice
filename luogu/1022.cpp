#include <iostream>
#include <string>
#include <cstdio>
#include <cctype>
#include <algorithm>
using namespace std;
int a[10005], b[10005];
int main()
{
	bool flag = 0, midflag = 0;
	int l = 0, r = 0;
	char ch, x;
	while ((ch = getchar()) != '\n')
	{
		if (isdigit(ch))
		{
			if (midflag == 0 && flag == 0)
				a[l] = a[l] * 10 + (ch - '0');
			else if (midflag == 1 && flag == 0)
				a[l] = a[l] * 10 - (ch - '0');
			else if (midflag == 0 && flag == 1)
				a[l] = a[l] * 10 - (ch - '0');
			else if (midflag == 1 && flag == 1)
				a[l] = a[l] * 10 + (ch - '0');
		}
		else if (ch == '+')
			++l, flag = 0;
		else if (ch == '-')
			++l, flag = 1;
		else if (ch == '=')
			midflag = 1, ++l, flag = 0;
		else if (isalpha(ch))
		{
			x = ch;
			if (a[l])
			{
				b[r] = a[l];
				++r;
				a[l] = 0;
			}
			else
			{
				if (midflag == 0)
					b[r] = 1;
				else
					b[r] = -1;
				++r;
			}
		}
	}
	int sum1 = 0, sum2 = 0;
	for (int i = 0; i <= l; ++i)
		sum1 += a[i];
	for (int i = 0; i <= r; ++i)
		sum2 += b[i];
	sum2 = -sum2;
	float f = sum1 * 1.0 / (sum2 * 1.0);
	printf("%c=%.3f\n", x, f ? f : 0);
	return 0;
}