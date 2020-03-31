#include <bits/stdc++.h>
using namespace std;
struct cartree
{
    struct node
    {
        int l, r, f;
        int val, index;
    };
    node tr[100005];
    int val[100005];
    int build(int n)
    {
        stack<int> s;
        s.push(1);
        for (int i = 2; i <= n; ++i)
        {
            while (!s.empty() && val[s.top()] > val[i])
                ;
        }
    }
};
