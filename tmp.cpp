#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
typedef long long ll;
int main()
{
    mt19937_64 mt;
    mt.seed(time(NULL));
    int t = 20;
    while (t--) {
        vector<string> vs;
        vector<vector<string>> v;
        vector<string> que;
        freopen((string("D:/4.3-data/D/") + to_string(t + 1) + ".in").c_str(), "w", stdout);
        int n = mt() % int(1e6) + 1;
        while (n) {
            int len = min(mt() % 10 + 1, 1ull * n);
            string s;
            s.resize(len);
            n -= len;
            while (len--) {
                s[len] = mt() % 26 + 'a';
            }
            vs.emplace_back(s);
        }
        int q = mt() % (int)2e5 + 1;
        for (int i = 1; i <= q; ++i) {
            if (mt() % 2) {
                int pos = mt() % vs.size();
                que.push_back(vs[pos]);
            } else {
                string s;
                int len = mt() % 10 + 1;
                while (len--) {
                    s.push_back(mt() % 26 + 'a');
                }
                que.push_back(s);
            }
        }
        while (vs.size()) {
            int len = min(vs.size(), mt() % int(1e4) + 1);
            vector<string> tmp;
            while (len--) {
                tmp.emplace_back(vs.back());
                vs.pop_back();
            }
            v.emplace_back(tmp);
            if (v.size() > 1e4) {
                break;
            }
        }
        for (auto& vec : v) {
            if (vec.size() == 0) {
                break;
            }
            for (int i = 0; i < vec.size(); ++i) {
                printf("%s%c", vec[i].c_str(), " \n"[i == vec.size() - 1]);
            }
        }
        printf("0\n");
        for (auto& str : que) {
            printf("%s\n", str.c_str());
        }
    }
    return 0;
}