/*
 * @lc app=leetcode.cn id=2013 lang=cpp
 *
 * [2013] 检测正方形
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

template<>
struct hash<pair<int, int>> {
    size_t operator()(const pair<int, int>& p) const {
        return hash<int>()(p.first) * 31 + hash<int>()(p.second);
    }
};
template<>
struct equal_to<pair<int, int>> {
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) const {
        return p1.first == p2.first && p1.second == p2.second;
    }
};

class DetectSquares {
public:
    unordered_map<pair<int, int>, int> mp_;
    DetectSquares() = default;
    
    void add(const vector<int>& point) {
        ++mp_[{point[0], point[1]}];
    }
    
    int count(const vector<int>& point) {
        auto res = 0;
        auto x = point[0], y = point[1];
        if (mp_.size() < 3) {
            return 0;
        }
        
        for (auto&[p, cnt] : mp_) {
            auto&[px, py] = p;
            if (x == px || y == py || abs(x - px) != abs(y - py)) {
                continue;
            }
            auto iter1 = mp_.find({px, y}), iter2 = mp_.find({x, py});
            if (iter1 == mp_.end() || iter2 == mp_.end()) {
                continue;
            }
            res += cnt * iter1->second * iter2->second;
        }
        return res;
    }
};
/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */
// @lc code=end

