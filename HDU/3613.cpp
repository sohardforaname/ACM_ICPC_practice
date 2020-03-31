#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
int value[500005];
int len[1000005];
int alpvalue[26];
void initVal(string &str)
{
	memset(value, 0, sizeof(value));
	value[0] = alpvalue[str[0] - 'a'];
	for (int i = 1; i < str.size(); ++i)
		value[i] = value[i - 1] + alpvalue[str[i] - 'a'];
}
void manacher(string &str)
{
	memset(len, 0, sizeof(len));
	string tmp = "(";
	for (int i = 0; i < str.size(); ++i)
	{
		tmp = tmp + "#" + str[i];
		if (i == str.size() - 1)
			tmp = tmp + "#)";
	}
	int mx = 0, id = 0;
	for (int i = 1; i < tmp.size() - 1; ++i)
	{
		len[i] = mx > i ? min(len[2 * id - i], mx - i) : 1;
		while (tmp[i + len[i]] == tmp[i - len[i]])
			++len[i];
		if (i + len[i] > mx)
		{
			mx = i + len[i];
			id = i;
		}
	}
	int i = len[0], j = tmp[0];
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	int n;
	cin >> n;
	while (n--)
	{
		for (int i = 0; i < 26; ++i)
			cin >> alpvalue[i];
		cin >> s;
		initVal(s);
		manacher(s);
	}
	return 0;
}