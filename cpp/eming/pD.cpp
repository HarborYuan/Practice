#include <iostream>
#include <algorithm>
#define INF 1000000007
using namespace std;

long a[100009],b[100009];

int main()
{
	long n,m,i,j,k,l,r;
	cin>>n;
	for (i=1;i<=n;i++)
		cin>>a[i];
	b[n]=a[n];
	for (i=n-1;i>=1;i--)
		b[i]=(b[i+1]+a[i])%INF;
	b[n+1]=0;
	cin>>m;
	for (i=1;i<=m;i++)
	{
		cin>>l>>r;
		k=0;
		for (j=l;j<r;j++)
			k=(k+a[j]*((b[j+1]-b[r+1]+INF)%INF))%INF;
		cout<<k<<endl;
	}
	return 0;
 } 
