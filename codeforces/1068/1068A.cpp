#include <iostream>
using namespace std;
int main()
{
	unsigned long long n, m, k, l;
	cin >> n >> m >> k >> l;
	if ((l + k) > n)
		cout << -1 << endl;
	else if (m > n)
		cout << -1 << endl;
	else
	{
		long long left;
		if ((l + k) % m == 0)
			left = (l + k) / m;
		else
			left = (l + k) / m + 1;
		if (left * m > n)
			cout << -1 << endl;
		else
			cout << left << endl;
	}
	//system("pause");
	return 0;
}