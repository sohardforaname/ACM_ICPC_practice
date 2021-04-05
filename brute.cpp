#include <bits/stdc++.h>

using namespace std;

struct node {
    int id {};
    vector<int> position;

    node() = default;

    node(int _id, const vector<int>& _position)
        : id(_id)
        , position(_position)
    {
    }

    bool operator<(const node& nd) const
    {
        return id < nd.id;
    }
};

const int N = 1e6 + 5;
int trie[N][26];
int cnt;
vector<node> dat[N];

int insert(const char* s)
{
    int root = 0;
    for (int i = 0; s[i]; ++i) {
        int nxt = s[i] - 'a';
        if (!trie[root][nxt]) {
            trie[root][nxt] = ++cnt;
        }
        root = trie[root][nxt];
    }
    return root;
}

int query(const char* s)
{
    int root = 0;
    for (int i = 0; s[i]; ++i) {
        int nxt = s[i] - 'a';
        if (!trie[root][nxt]) {
            return -1;
        }
        root = trie[root][nxt];
    }
    return root;
}

bool cmp(const node& a, const node& b)
{
    return a.position.size() > b.position.size();
}

void dfs(int u)
{
    sort(dat[u].begin(), dat[u].end(), cmp);
    for (int i = 0; i < 26; ++i) {
        if (trie[u][i]) {
            dfs(trie[u][i]);
        }
    }
}

typedef unsigned long long ull;
const ull p = 131;

ull getHash(const string& str)
{
    ull val = 0;
    for (auto ch : str) {
        val = val * 131 + ch;
    }
    return val;
}

vector<pair<int, string>> doc;
vector<string> que;
string str;

int main(int argc, char** argv)
{
    freopen((string("D:/4.3-data/D/") + argv[1] + string(".in")).c_str(), "r", stdin);
    freopen((string("D:/4.3-data/D/") + argv[1] + string(".out")).c_str(), "w", stdout);
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    int docid = 1;
    while (getline(cin, str) && str != "0") {
        doc.clear();
        int pos = 0;
        string tmp;
        stringstream ss;
        ss << str;
        while (ss >> tmp) {
            doc.emplace_back(pos++, tmp);
        }
        for (auto& p : doc) {
            int res = query(p.second.c_str());
            if (res == -1) {
                dat[insert(p.second.c_str())].emplace_back(docid, vector<int>(1, p.first));
            } else {
                vector<node>& v = dat[res];
                node nd = node(docid, vector<int>(1, p.first));
                int ps = lower_bound(v.begin(), v.end(), nd) - v.begin();
                if (ps == v.size()) {
                    v.push_back(nd);
                } else {
                    v[ps].position.push_back(p.first);
                }
            }
        }
        ++docid;
    }
    dfs(0);
    while (getline(cin, str)) {
        que.push_back(str);
    }
    ull pos = 0;
    for (int i = 0; i < que.size(); ++i) {
        string& s = que[pos];
        //printf("current: %s\n", s.c_str());
        int res = query(s.c_str());
        if (res == -1) {
            printf("0\n");
        } else {
            for (auto& nd : dat[res]) {
                printf("%d", nd.id);
                for (auto& num : nd.position) {
                    printf("->%d", num);
                }
                printf("\n");
            }
        }
        pos = (getHash(s) + pos) % que.size();
    }
    return 0;
}