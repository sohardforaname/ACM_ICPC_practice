#include "../base.h"
/*
 * @lc app=leetcode.cn id=329 lang=cpp
 *
 * [329] 矩阵中的最长递增路径
 */

// @lc code=start
const int dir[4][2] = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };
class Solution {
public:
    bool vis[200][200];
    int dis[200][200];
    int n, m;
    bool check(int i, int j)
    {
        return i >= 0 && i < n && j >= 0 && j < m;
    }
    int dfs(int i, int j, vector<vector<int>>& mat)
    {
        if (dis[i][j])
            return dis[i][j];
        dis[i][j] = 1;
        for (int k = 0; k < 4; ++k) {
            int x = i + dir[k][0], y = j + dir[k][1];
            if (check(x, y) && mat[x][y] > mat[i][j]) {
                vis[x][y] = 1;
                dis[i][j] = max(dis[i][j], dfs(x, y, mat) + 1);
                vis[x][y] = 0;
            }
        }
        return dis[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix)
    {
        int maxn = 0;
        n = matrix.size(), m = matrix.front().size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                maxn = max(maxn, dfs(i, j, matrix));
            }
        }
        return maxn;
    }
};
// @lc code=end
