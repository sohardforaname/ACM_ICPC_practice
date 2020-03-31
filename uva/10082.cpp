#include <cstdio>
using namespace std;
const char ch[] = { "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;\'ZXCVBNM,./" };
int main()
{
	char c;
	int i;
	while ((c = getchar()) != EOF)
	{
		for (i = 0; ch[i] && c != ch[i]; ++i);
		if (ch[i])
			putchar(ch[i - 1]);
		else
			putchar(c);
	}
	return 0;
}