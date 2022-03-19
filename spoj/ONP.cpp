#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
stack<char> s;
char str[N];
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%s", str);
        for (int i = 0; str[i]; ++i)
        {
            if (isalpha(str[i]))
                putchar(str[i]);
            else if (str[i] != '(' && str[i] != ')')
                s.push(str[i]);
            else if (str[i] == '(')
                s.push(str[i]);
            else
            {
                while (s.top() != '(')
                {
                    putchar(s.top());
                    s.pop();
                }
                s.pop();
            }
        }
        putchar('\n');
    }
    return 0;
}