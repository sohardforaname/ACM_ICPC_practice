#include "../base.h"
/*
 * @lc app=leetcode.cn id=224 lang=cpp
 *
 * [224] 基本计算器
 */

// @lc code=start
class Solution {
public:
    unordered_map<char, int> mp;
    bool firstop = 0;
    long long calculate(const string& s)
    {
        mp['+'] = mp['-'] = 1;
        mp['*'] = mp['/'] = 2;
        stack<long long> ids;
        stack<char> ops;
        auto cal = [&]() {
            char ch = ops.top();
            ops.pop();
            int a = ids.top();
            ids.pop();
            int b = ids.top();
            ids.pop();
            if (ch == '+') {
                ids.push(b + a);
            } else if (ch == '-') {
                ids.push(b - a);
            }
        };
        bool flag = 0;
        for (int i = 0; i < s.size();) {
            if (isdigit(s[i])) {
                flag = 1;
                long long tmp = 0;
                while (i < s.size() && isdigit(s[i])) {
                    tmp = tmp * 10 + s[i] - '0';
                    ++i;
                }
                ids.push(tmp);
            } else if (s[i] == ' ') {
                ++i;
            } else {
                if (s[i] == '(') {
                    ops.push(s[i]);
                    flag = 0;
                } else if (s[i] == ')') {
                    while (ops.top() != '(') {
                        cal();
                    }
                    ops.pop();
                } else {
                    while (ops.size() && mp[ops.top()] >= mp[s[i]]) {
                        cal();
                    }
                    if (!flag)
                        ids.push(0);
                    ops.push(s[i]);
                }
                ++i;
            }
        }
        while (ops.size()) {
            cal();
        }
        return ids.top();
    }
};
// @lc code=end
