#include <algorithm>
#include <cstring>
#include <deque>
#include <iostream>
using namespace std;
int dp[200005], num[200005];
struct node {
    int v, num;
    node(int a, int b)
    {
        v = a, num = b;
    }
};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, l, r;
    cin >> n >> l >> r;
    for (int i = 0; i <= n; ++i)
        cin >> num[i];
    deque<node> que;
    dp[0] = 0;
    for (int i = l; i <= n; ++i) {
        /*for(int j=i-r;j<=i-l;++j)
            if(j>=0)
                dp[i]=max(dp[i],dp[j]+num[i]);*/
        while (!que.empty() && dp[i - l] >= que.back().v) //ά��������
            que.pop_back();
        que.push_back(node(dp[i - l], i - l)); //���ܵ���i�Ľڵ����
        while (!que.empty() && que.front().num + r < i) //���Ѿ��޷�����i�Ľڵ����
            que.pop_front();
        dp[i] = que.front().v + num[i]; //�õ��Ķ���һ�������ֵ
    }
    int maxx = -0x7fffffff;
    //for(int i=0;i<=n;++i)
    //cout<<dp[i]<<endl;
    for (int i = n - r + 1; i <= n; ++i)
        maxx = max(maxx, dp[i]);
    cout << maxx << endl;
    return 0;
}
