#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
stack<int> s;
char str[N];
int main()
{
    scanf("%s", str);
    int len = strlen(str);
    int ans = 0;
    for (int i = 0; i < len; ++i)
    {
        if (str[i] == '(')
            s.push(i);
        else
        {
            if (s.size())
                s.pop();
            else
                ++ans;
        }
    }
    printf("%d\n", len - ans - (int)s.size());
    return 0;
}