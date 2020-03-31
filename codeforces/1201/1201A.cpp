#include <bits/stdc++.h>
using namespace std;
string str[1005];
int cnt[5][1005],p[1005];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;++i)
        cin>>str[i];
    for(int i=0;i<m;++i)
        cin>>p[i];
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            ++cnt[str[i][j]-'A'][j];
    long long sum=0;
    for(int i=0;i<m;++i)
    {
        int maxx=0,pos=0;
        for(int j=0;j<5;++j)
            if(maxx<cnt[j][i])
                maxx=cnt[j][i];;
        sum+=maxx*p[i];
    }
    cout<<sum<<endl;
    return 0;
}
