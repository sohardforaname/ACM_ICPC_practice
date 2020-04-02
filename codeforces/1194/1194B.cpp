#include <bits/stdc++.h>
int x[50005],y[50005];
using namespace std;
vector<string>vec;
int main()
{
    int n,a,b;
    cin>>n;
    while(n--)
    {
        vec.clear();
        cin>>a>>b;
        memset(x,0,sizeof(x));
        memset(y,0,sizeof(y));
        string str;
        for(int i=0;i<a;++i)
        {
            cin>>str;
            vec.push_back(str);
            int pos=0;
            for(int j=0;j<b;++j)
                if(str[j]=='*')
                    ++y[j],++pos;
            x[i]=pos;
        }
        int minn=0x3f3f3f3f;
        for(int i=0;i<a;++i)
            for(int j=0;j<b;++j)
            {
                if(vec[i][j]=='.')
                    minn=min(minn,a+b-x[i]-y[j]-1);
                else
                    minn=min(minn,a+b-x[i]-y[j]);
            }
        cout<<minn<<endl;
    }
    return 0;
}
