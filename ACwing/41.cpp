#include <bits/stdc++.h>
using namespace std;
class MinStack {
public:
    stack<int> s1, s2;
    MinStack() { }
    void push(int x)
    {
        if (s2.empty() || s2.top() >= x)
            s2.push(x);
        s1.push(x);
    }
    void pop()
    {
        if (s1.top() == s2.top())
            s2.pop();
        s1.pop();
    }
    int top()
    {
        return s1.top();
    }
    int getMin()
    {
        return s2.top();
    }
};
int main()
{
    MinStack minStack;
    minStack.push(-1);
    minStack.push(3);
    minStack.push(-4);
    cout << minStack.getMin() << endl;
    minStack.pop();
    cout << minStack.top() << endl;
    cout << minStack.getMin() << endl;
    return 0;
}