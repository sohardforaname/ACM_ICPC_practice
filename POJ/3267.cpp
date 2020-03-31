#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int dp[305];
vector<string>str;
int main()
{
	string tmp,s;
	int n,m;
	cin>>n>>m;
	cin>>tmp;
	for(int i=0;i<n;++i)
		cin>>s,str.push_back(s);
	int ps,pd,sta;
	dp[tmp.size()]=0;
	int len;
	for(int i=tmp.size()-1;i>=0;--i)
	{
		dp[i]=dp[i+1]+1; 
		for(int j=0;j<n;++j)
		{
			len=str[j].size();
			//cout<<"l="<<len<<endl;
			if(i+len<=tmp.size()&&tmp[i]==str[j][0])
			{
				//cout<<"ok"<<endl;
				pd=0,ps=i;
				while(ps<tmp.size()&&pd<len)
				{
					if(tmp[ps]==str[j][pd])
						++pd,++ps;
					else
						++ps;
				}
				//cout<<"pd="<<pd<<endl;
				if(pd==len)
					dp[i]=min(dp[i],dp[ps]+(ps-i)-len);
			}
		}
		//cout<<dp[i]<<endl;
	}
	cout<<dp[0]<<endl;
	return 0;
}