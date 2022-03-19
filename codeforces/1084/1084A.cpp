#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int num[105];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> num[i];
	int ans = 1e6, sum;
	for (int i = 0; i < 100; ++i)//x
	{
		sum = 0;
		for (int j = 0; j < n; ++j)
			sum += num[j] * (abs(i - j) + j + i);
		ans = min(ans, sum);
	}
	cout << ans * 2 << endl;
	return 0;
}