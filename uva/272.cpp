#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	char ch;
	int index = 0;
	while ((ch = getchar()) != EOF)
	{
		if (index == 0)
		{
			if (ch == '\"')
				index = 1, putchar('`'), putchar('`');
			else
				putchar(ch);
		}
		else if (index == 1)
		{
			if (ch == '\"')
				index = 0, putchar('\''), putchar('\'');
			else
				putchar(ch);
		}
	}
	return 0;
}
