#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	long long a,b,t;
	long long m=1e12+10;
	cin>>a>>b>>t;
	long n;
	cin>>n;
	long long ans=0;
	while (n--)
	{
		long long k;
		cin>>k;
		if (k<=b-t)
		{
			if (max(a,k-1)<=b-t&&(a-k+1)<m)
			{
				m=a-k+1;
				ans=min(a,k-1);
			}
			a=max(a,k)+t;
		}
	}
	if (a<=b-t)
		ans=a;
	cout<<ans<<endl;
	return 0;
 } 
