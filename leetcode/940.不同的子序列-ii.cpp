#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

class Solution {
public:
    vector<long long> dp;
    int distinctSubseqII(const string& s)
    {
        vector<int> lst(26, -1);
        dp.resize(s.size() + 1);
        dp[0] = 1;
        for (int i = 0; i < s.size(); ++i) {
            int p = s[i] - 'a';
            dp[i + 1] = dp[i] * 2 % mod;
            if (lst[p] != -1) {
                dp[i + 1] -= dp[lst[p]];
                dp[i + 1] %= mod;
            }
            lst[p] = i;
        }
        dp[s.size()] = (dp[s.size()] - 1 + mod) % mod;
        return dp[s.size()];
    }
};