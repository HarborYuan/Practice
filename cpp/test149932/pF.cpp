#include <iostream>
#include <cmath>
using namespace std;

long long quickmi(long long a,long long b,long long k)
{
	long long ans=1;
	while (b>0)
	{
		if (b % 2==1)
			ans=(ans*a) % k;
		b=floor(b/2);
		a=(a*a) % k;
	 } 
	 return ans;
}

bool sushu(long long n)
{
	for (long long i=2;i<=sqrt(n);i++)
		if (n%i==0)
			return 0;
	return 1;
}

int main()
{
	long long a,p,i,j,k;
	while (true)
	{
		cin>>p>>a;
		if (p==0 && a==0)
			return 0;
		if (sushu(p))
		{
			cout<<"no"<<endl;
			continue;
		}
		if (quickmi(a,p,p)==a)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}
}
