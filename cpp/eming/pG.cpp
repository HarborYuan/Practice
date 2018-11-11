#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
long n,m,i,j,k,r,l;
const double pi=3.1415926535;
long a[100009];

void erf(long l,long r)
{
	long mid=(l+r)/2;
	double x=a[1]/double(mid);
	long num=mid;
	for (i=2;i<=m;i++)
	{
		if (a[i]<x)
			break;
		num+=int(a[i]/mid);
	}
}
int main()
{
	while (cin>>n>>m)
	{
		for (i=1;i<=m;i++)
			cin>>a[i];
		sort(a+1,a+1+m,greater<data-type>());
		erf(1,n);
	}
	return 0;
}
