#include <iostream>
#include <cstring>
using namespace std;
char pre[30],in[30];
int recover(int prel,int prer,int inl,int inr)
{
    if(prel<=prer&&inl<=inr)
    {
        int pos;
        for(pos=inl;pos<=inr;++pos)
            if(in[pos]==pre[prel])
                break;
        int left=pos-inl;
        int right=inr-pos;
        if(left>0)
            recover(prel+1,prel+left,inl,pos-1);
        if(right>0)
            recover(prer-right+1,prer,pos+1,inr);
        cout<<in[pos];
    }
}
int main()
{
    while(cin>>pre>>in)
    {
        int len = strlen(pre);
        recover(0,len-1,0,len-1);
        cout<<endl;
    }
    return 0;
}
