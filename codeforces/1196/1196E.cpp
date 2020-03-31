#include <bits/stdc++.h>//exist bug
using namespace std;
int main()
{
    int T,n,m;
    cin>>T;
    while(T--)
    {
        cin>>n>>m;
        cout<<"YES"<<endl;
        int xpos=1,ypos=2;
        for(int i=0;i<n;++i)
        {
            cout<<xpos<<" "<<ypos<<endl;
            ++ypos;
            if(ypos==int(1e9))
                ++xpos,ypos=1;
        }
        ++xpos;
        for(int i=0;i<m;++i)
        {
            cout<<xpos<<" "<<ypos<<endl;
            ++ypos;
            if(ypos==int(1e9))
                ++xpos,ypos=1;
        }
    }
    return 0;
}
