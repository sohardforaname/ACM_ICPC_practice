#include <cstdio>
#include <cstring>
#include <cctype>
const char aa[] = { "A...3..HIL.JM.O...2TUVWXY51SE.Z..8." };
char trans(char ch)
{
	if (isalpha(ch)) return aa[ch - 'A'];
	else return aa[ch - '1' + 26];
}
int main()
{
	char ch[100];
	while (scanf("%s", ch) != EOF)
	{
		int len = strlen(ch);
		for (int i = 0; i < len; ++i)
			if (ch[i] == '0')
				ch[i] = 'O';
		bool x = 1, y = 1;
		for (int i = 0; i < len / 2 + 1; ++i)
		{
			if (ch[i] != ch[len - i - 1]) 
				x = 0;
			if (ch[i] != trans(ch[len - i - 1]))
				y = 0;
		}
		if (!x && !y) 
			printf("%s -- is not a palindrome.\n\n", ch);
		else if (x && !y) 
			printf("%s -- is a regular palindrome.\n\n", ch);
		else if (!x && y)
			printf("%s -- is a mirrored string.\n\n", ch);
		else
			printf("%s -- is a mirrored palindrome.\n\n", ch);
	}
	return 0;
}