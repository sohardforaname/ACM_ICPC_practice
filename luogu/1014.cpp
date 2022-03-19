#include <iostream>
using namespace std;
int num[20005];
void init()
{
	for (int i = 1; i * (i + 1) / 2 <= 20000000; ++i)
		num[i] = i * (i + 1) / 2;
}
int main()
{
	int n;
	cin >> n;
	int pos = 0;
	init();
	for (pos; num[pos] <= n; ++pos);
	pos -= 1;
	if (num[pos] == n)
	{
		if (pos % 2 == 0)
			cout << pos << '/' << 1 << endl;
		else
			cout << 1 << '/' << pos << endl;
	}
	else
	{
		int l = n - num[pos];
		if (pos % 2 == 0)
			cout << pos + 2 - l << '/' << l << endl;
		else
			cout << l << '/' << pos + 2 - l << endl;
	}
	return 0;
}