#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int num[100005];
int main()
{
	long long sum = 0;
	int m, n;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> num[i], sum += num[i];
	sort(num, num + n);
	long long ans = 0;
	int h = 0;
	for (int i = 0; i < n - 1; ++i)
	{
		if (num[i] > h)
			++h, ++ans;
		else
			++ans;
	}
	if (num[n - 1] == h)
		++ans;
	else
		ans += num[n - 1] - h;
	cout << sum - ans << endl;
	//system("pause");
	return 0;
}