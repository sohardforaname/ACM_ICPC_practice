#include <iostream>
using namespace std;
int main()
{
	double s,x;
	cin>>s>>x;
	double k=7,sum=0;
	while(s-x>sum)
	{
		sum+=k;
		k*=0.98;	
	}
	if(k<2*x)
		cout<<"y"<<endl;
	else 
		cout<<"n"<<endl;
	return 0;	
}