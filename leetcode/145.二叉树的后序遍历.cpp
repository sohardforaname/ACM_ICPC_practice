#include "../base.h"
/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
    vector<int> postorderTraversal(TreeNode* root)
    {
        if (!root)
            return move(vector<int>());
        stack<TreeNode*> s;
        vector<int> v;
        TreeNode *p = root, *lst = nullptr;
        while (p) {
            s.push(p);
            p = p->left;
        }
        while (s.size()) {
            //��ʱp = nullptr�ҵ���Ҷ��
            p = s.top();
            s.pop();
            if (!(p->right) || p->right == lst) {
                v.emplace_back(p->val);
                lst = p;
            } else {
                s.push(p);
                p = p->right;
                while (p) {
                    s.push(p);
                    p = p->left;
                }
            }
        }
        return move(v);
    }
};
// @lc code=end
