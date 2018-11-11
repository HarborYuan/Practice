#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

bool sushu(long n)
{
	for (long i=2;i<=sqrt(n);i++)
		if (n%i==0)
			return 0;
	return 1;
}

int main()
{
	long n;
	cin>>n;
	if (sushu(n))
	{
		cout<<1;
		return 0;
	}
	if (n%2==0)
	{
		cout<<2;
		return 0;
	}
	if (sushu(n-2))
	{
		cout<<2;
		return 0;
	}
	cout<<3;
	return 0;
}
