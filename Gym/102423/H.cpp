#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
set<string> v;
int main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    string s, str;
    cin >> s >> str;
    for (int i = 0; i < str.size() - 1; ++i)
        v.insert(str.substr(0, i + 1) + str.substr(i + 2));
    for (int i = 0; i < str.size(); ++i)
        for (int j = 0; j < s.size(); ++j)
            v.insert(str.substr(0, i + 1) + s[j] + str.substr(i + 1));
    for (int i = 0; i < s.size(); ++i)
        v.insert(s[i] + str);
    v.insert(str.substr(1));
    for (int i = 0; i < str.size(); ++i)
        for (int j = 0; j < s.size(); ++j)
            if (s[j] != str[i])
            {
                swap(s[j], str[i]);
                v.insert(str);
                swap(s[j], str[i]);
            }
    for (auto &i : v)
        cout << i << '\n';
    return 0;
}