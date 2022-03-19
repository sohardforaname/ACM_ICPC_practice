#include <iostream>
#include <string>
#include <bitset>
#include <algorithm>
//����bitset����
using namespace std;
bitset<100005>ans[26];
bitset<100005>k;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string a;
	for (int i = 0; i < 26; ++i)
		ans[i].set();
	for (int i = 0; i < a.size(); ++i)
		ans[a[i] - 'a'][i] = 1;
	int n;
	cin >> n;
	while (n--)
	{
		int m, s, t;
		char ch; 
		string b;
		cin >> m;
		if (m == 1)
		{
			cin >> s >> ch;
			ans[a[s] - 'a'][s - 1] = 0;
			ans[(a[s] = ch) - 'a'][s - 1] = 1;
		}
		else
		{
			cin >> s >> t >> b;
			for (int i = 0; i < b.size(); ++i)
				k &= (ans[b[i] - 'a'] >> j);
			int left = (k >> s).count(), right = (k >> (t - b.size() + 2)).count();//ans����ȥ��ƥ�䲿��ǰ�棬ȥ��ƥ�䲿�ֵĺ��棬
			//+2��Ϊ���ַ����ļ���������+1ͬʱ+1Ϊ���ַ�����1ƥ���ɴ�0ƥ�䡣
			cout << max(0, left - right) << endl;
		}
	}
	return 0;
}
