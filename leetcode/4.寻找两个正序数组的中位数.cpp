#include "../base.h"
/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        const int INF = 0x3f3f3f3f;
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int n = nums1.size(), m = nums2.size();
        int l = 0, r = n;
        int mid1, mid2;
        int nlmx, mlmx, nrmi, mrmi, i, j;
        while (l <= r) {
            i = (l + r) / 2;
            j = (m + n + 1) / 2 - i;
            // cout << l << " " << r << endl;
            nlmx = i == 0 ? -INF : nums1[i - 1];
            mlmx = j == 0 ? -INF : nums2[j - 1];
            nrmi = i == n ? INF : nums1[i];
            mrmi = j == m ? INF : nums2[j];
            if (nlmx <= mrmi) {
                l = i + 1;
                mid1 = max(nlmx, mlmx);
                mid2 = min(nrmi, mrmi);
            } else
                r = i - 1;
        }
        return (m + n) % 2 ? mid1 : (mid1 + mid2) / 2.0;
    }
};
// @lc code=end
