#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int num[105];
bool tag[105];
int main()
{
	int ans = 0;
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
		cin >> num[i];
	int pos, neg = 0;
	for (int i = 0; i < n; ++i)
	{
		pos = neg = 0;
		memset(tag, 0, sizeof(tag));
		for (int j = 0; j * k + i < n; ++j)
			tag[j * k + i] = 1;
		for (int j = 0; j * k + i >= 0; --j)
			tag[j * k + i] = 1;
		for (int j = 0; j < n; ++j)
		{
			if (!tag[j])
			{
				if (num[j] == 1)
					++pos;
				else if (num[j] == -1)
					++neg;
			}
		}
		ans = max(ans, abs(pos - neg));
	}
	cout << ans << endl;
	return 0;
}