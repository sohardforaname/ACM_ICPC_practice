#include <bits/stdc++.h>
using namespace std;
void solve()
{
    string s;
    cin >> s;
    stack<int> st;
    int cnt = 0;
    int ans = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == 'A')
            st.push(i);
        else
        {
            if (st.size())
                ans += 2, st.pop();
            else
                ++cnt;
        }
    }
    cout << s.size() - ans - (cnt / 2) * 2 << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}