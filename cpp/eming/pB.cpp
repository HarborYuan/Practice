#include <iostream>
using namespace std;

long n,a[25];
int main()
{
	cin>>n;
	for (int i=0;i<n;i++)
		cin>>a[i];
	long ans=0;
	while (a[0]!=0)
	{
		long t=a[0];
		for (int i=0;i<=t-1;i++)
			a[i]=a[i+1];
		a[t]=t;
		ans++;
		if (ans>=50000000)
		{
			cout<<"-1s";
			return 0;
		}
	}
	cout<<ans<<endl;
	return 0;
}
