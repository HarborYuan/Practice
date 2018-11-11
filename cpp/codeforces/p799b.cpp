#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	long n,k,i,j,sum,wei=0,zero=0,one=0,nn,onet=0,zerot=0;
	cin>>n>>k;
	if (n==0)
	{
		cout<<0<<endl;
		return 0;
	}
	nn=n;
	while (n>0)
	{
		if (!(n%10))
			zero++;
		else
		{
			one++;
		}
		wei++;
		n/=10;
	}
	if (zero==0)
	{
		cout<<-1;
		return 0;
	}
	if (zero<k)
	{
		cout<<wei-1<<endl;
		return 0;
	}
	while (nn>0)
	{
		if (!(nn%10))
		{
			zerot++;
			if (zerot==k)
			{
				cout<<onet<<endl;
				return 0;
			}
		}
		else
		{
			onet++;
		}
		nn/=10;
	}
	return 0;
}
