#include "../base.h"
/*
 * @lc app=leetcode.cn id=745 lang=cpp
 *
 * [745] 前缀和后缀搜索
 */

// @lc code=start
class WordFilter {
public:
    vector<array<int, 30>> trie;
    vector<int> weight;
    int cnt;
    auto idx(const char& ch) -> int
    {
        return ch - '_';
    };
    WordFilter(vector<string>& words)
    {
        int len = 0, cnt = 0;
        for (int i = 0; i < words.size(); ++i) {
            len += words[i].size() * words[i].size() * 2 + 2;
        }
        trie.resize(len + 1, array<int, 30>({}));
        weight.resize(len + 1, -1);
        for (int i = 0; i < words.size(); ++i) {
            string str = '_' + words[i], &sref = words[i];
            for (int j = 0; j < sref.size(); ++j) {
                string tmp = sref.substr(j) + str;
                int root = 0;
                for (int k = 0; k < tmp.size(); ++k) {
                    int id = idx(tmp[k]);
                    if (!trie[root][id])
                        trie[root][id] = ++cnt;
                    root = trie[root][id];
                    weight[root] = i;
                }
            }
        }
    }

    int f(string prefix, string suffix)
    {
        string s = move(suffix) + '_' + move(prefix);
        int root = 0;
        for (int i = 0; i < s.size(); ++i) {
            int id = idx(s[i]);
            if (!trie[root][id])
                return -1;
            root = trie[root][id];
        }
        return weight[root];
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
// @lc code=end
