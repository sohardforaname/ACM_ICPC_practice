#include <iostream>
#include <string>
using namespace std;
int nextarray[1000005];
void getnext(string &str)
{
	nextarray[0] = -1;
	int j = -1, k = 0;
	while (k < str.size())
	{
		if (j == -1 || str[j] == str[k])
			nextarray[++k] = ++j;
		else
			j = nextarray[j];
	}
}
void kmp(string &a, string &b)
{
	int i = 0, j = 0;
	while (j < a.size())
	{
		if (i == -1 || a[j] == b[i])
			++j, ++i;
		else
			i = nextarray[i];
		if (i == b.size())
			cout << j - b.size() + 1 << endl, i = nextarray[i];
	}
}
int main()
{
	string a, b;
	cin >> a >> b;
	getnext(b);
	kmp(a, b);
	for (int i = 0; i < b.size(); ++i)
	{
		cout << nextarray[i + 1];
		if (i < b.size() - 1)
			cout << " ";
		else
			cout << endl;
	}
	return 0;
}