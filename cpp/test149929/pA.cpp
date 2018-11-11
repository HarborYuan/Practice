#include <iostream>
#include <algorithm>
using namespace std;

long a[310][310]={0};
const int large=1000000000;
long ans[310],b[310];

int main()
{
	long n,m,i,j,k,x;
	cin>>n>>m;
	for (i=0;i<310;i++)
		for (j=0;j<310;j++)
			if (i!=j)
				a[i][j]=a[j][i]=large;
	for (i=0;i<m;i++)
	{
		cin>>x;
		for (j=0;j<x;j++)
			cin>>b[j];
		for (j=0;j<x;j++)
			for (k=j+1;k<x;k++)
				a[b[j]][b[k]]=a[b[k]][b[j]]=1;
	}
	long mint=large;
	for (k=1;k<=n;k++)
		for (i=1;i<=n;i++)
			for (j=1;j<=n;j++)
				a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
	for (i=1;i<=n;i++)
	{
		long maxt=0;
		for (j=1;j<=n;j++)
			maxt+=a[i][j];
		mint=min(mint,100*maxt/(n-1));
	}
	cout<<mint<<endl;
	return 0;
 } 
