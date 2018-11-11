#include<iostream>
#include<math.h>
using namespace std;
int gcd(int a,int b)
{
	if(!a)
		return b;
	return gcd(b%a,a);
}
int main()
{
	char str[100];	int num,k,all,a,b,i,j,mina,minb,l;
	while(cin>>str)
	{
		if (str[1]!='.')
			return 0;
		mina=minb=1000000000;
		for(i=2,all=0,l=0;str[i]!='.';i++)
		{
			all=all*10+str[i]-48;
			l++;
		}
		for(num=all,k=1,i=1;i<=l;i++)
		{
			num/=10;
			k*=10;
			a=all-num;
			b=(int)pow(10.0,l-i)*(k-1);
			j=gcd(a,b);
			if(b/j<minb)
			{
				mina=a/j;	minb=b/j;
			}
		}
		cout<<mina<<'/'<<minb<<endl;
	}
	return 0;
}

