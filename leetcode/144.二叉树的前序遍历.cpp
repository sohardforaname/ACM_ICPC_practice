#include "../base.h"
/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode()
        : val(0)
        , left(nullptr)
        , right(nullptr)
    {
    }
    TreeNode(int x)
        : val(x)
        , left(nullptr)
        , right(nullptr)
    {
    }
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x)
        , left(left)
        , right(right)
    {
    }
};

// @lc code=start
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root)
    {
        if (!root)
            return move(vector<int>());
        stack<TreeNode*> s;
        vector<int> v;
        TreeNode* p = root;
        while (p) {
            v.emplace_back(p->val);
            s.push(p);
            p = p->left;
        }
        while (s.size() || p) {
            while (p) {
                v.emplace_back(p->val);
                s.push(p);
                p = p->left;
            }
            if (s.size()) {
                p = s.top();
                s.pop();
                p = p->right;
            }
        }
        return move(v);
    }
};
// @lc code=end
