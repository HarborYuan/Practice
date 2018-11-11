#include <iostream>
#include <cmath>
using namespace std; 

long a[100005];

int main()
{
	long n,i,k,maxn=-0x7f7f7f7f,minn=0x7f7f7f7f;
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>k;
		a[i]=k;
		if (k<minn)
			minn=k;
		if (k>maxn)
			maxn=k;
	}
	long ans=n;
	if (minn==maxn)
	{
		cout<<0<<endl;
		return 0;
	}
	for (i=1;i<=n;i++)
	{
		if (a[i]==maxn)
			ans--;
		if (a[i]==minn)
			ans--;
	}
	cout<<ans<<endl;
	return 0;
}
