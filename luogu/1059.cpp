#include <iostream>
using namespace std;
bool vis[1005];
int main()
{
	int n, a, s = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a;
		if (!vis[a])
		{
			++s;
			vis[a] = 1;
		}
	}
	cout << s << endl;
	for (int i = 0; i < 1005; ++i)
		if (vis[i])
			cout << i << " ";
	cout << endl;
	return 0;
}