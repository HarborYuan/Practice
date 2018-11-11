#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	long n,sum;
	cin>>n>>sum;
	long a[11],b[11],i,j;
	for (i=0;i<n;i++)
		a[i]=i+1;
	do
	{
		for (i=0;i<n;i++)
			b[i]=a[i];
		for (i=n;i>1;i--)
			for (j=0;j<i-1;j++)
				b[j]=b[j]+b[j+1];
		if (b[0]==sum)
			break;
	}while (next_permutation(a,a+n));
	for (i=0;i<n;i++)
		cout<<a[i]<<' ';
	return 0;
 } 
