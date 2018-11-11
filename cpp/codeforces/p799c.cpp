#include <iostream>
#include <algorithm>
using namespace std;

long a[200005],b[200005],c[200005];

int main()
{
	long n,k,i,j,sum=0;
	cin>>n>>k;
	for (i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	for (i=1;i<=n;i++)
		cin>>b[i];
	for (i=1;i<=n;i++)
		c[i]=b[i]-a[i];
	sort(c+1,c+n+1);
	for (i=1;(i<=n-k)&&c[i]<0;i++)
		sum+=c[i];
	cout<<sum<<endl;
	return 0;
}
