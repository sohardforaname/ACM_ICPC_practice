#include <bits/stdc++.h>
using namespace std;
bitset<32>bit[1005];
int main()
{
	freopen("out.txt", "w", stdout);
	string str;
	unsigned int tmp;
	int n;
	stringstream ss;
	while (cin >> n)
	{
		unsigned int t;
		for (int i = 0; i < n; ++i)
		{
			tmp = 0;
			cin >> str;
			for (auto& j : str)
				if (j == '.')
					j = ' ';
			ss.clear();
			ss << str;
			for (int j = 0; j < 4; ++j)
			{
				ss >> t;
				tmp += (t << (8 * (3 - j)));
			}
			bit[i] = tmp;
		}
		int i;
		bool f = 0;
		for (i = 31; i >= 0; --i)
			for (int j = 1; j < n; ++j)
				if (bit[j][i] != bit[j - 1][i])
				{
					f = 1;
					goto lab;
				}
	lab:
		bit[n] = bit[0];
		for (int k = i; k >= 0; --k)
			bit[n].set(k, 0);
		bit[n + 1].reset();
		for (int k = 31; k > i; --k)
			bit[n + 1].set(k);
		unsigned long t1[2];
		t1[0] = bit[n].to_ulong(), t1[1] = bit[n + 1].to_ulong();
		int outtmp[4], pos = 0;
		for (int i = 0; i < 2; ++i)
		{
			pos = 0;
			while (pos<4)
			{
				outtmp[pos++] = t1[i] % 256;
				t1[i] /= 256;
			}
			for (int i = 3; i >= 0; --i)
				cout << outtmp[i] << (!i ? '\n' : '.');
		}
	}
	return 0;
}
