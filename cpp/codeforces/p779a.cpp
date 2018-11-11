#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
long a[6],b[6],c[6];

int main()
{
	long i,j,k,n,sum=0,ans=0;
	cin>>n;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	for (i=1;i<=n;i++)
	{
		cin>>k;
		a[k]++;
	}
	for (i=1;i<=n;i++)
	{
		cin>>k;
		b[k]++;
	}
	for (i=1;i<=5;i++)
	{
		c[i]=a[i]-b[i];
		if ((c[i]%2))
		{
			cout<<-1<<endl;
			return 0;
		}
		if (c[i]>0)
			sum+=c[i]/2;
	}
	cout<<sum<<endl;
	return 0;
}
