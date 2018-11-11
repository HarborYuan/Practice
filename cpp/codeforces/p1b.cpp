#include <iostream>
#include <cstring>
#include <set>
using namespace std;

char a[1000010];

void cc(long x)
{
	if (x==0)
		return;
	cc((x-1)/26);
	cout<<char((x-1)%26+'A');
}

int main()
{
	long n,pos,len;
	char *p;
	bool flag;
	cin>>n;
	for (long i=1;i<=n;i++)
	{
		flag=false;
		cin>>a;
		len=strlen(a);
		for (long j=1;j<len-1;j++)
		{
			if (a[j]=='C' && a[j+1]<65 && a[j-1]<65)
			{
			flag=true;
			pos=j;
			break;
			}
		}
		if (flag)
		{
			long num1=0,num2=0;
			for (long j=1;j<=pos-1;j++)
				num1=num1*10+a[j]-48;
			for (long j=pos+1;j<=len-1;j++)
				num2=num2*10+a[j]-48;
			cc(num2);
			cout<<num1<<endl;
		}
		if (!flag)
		{
			long num1;
			for (num1=0,p=a;*p>64;p++)
				num1=num1*26+*p-64;
			cout<<'R'<<p<<'C'<<num1<<endl;
		}
	}
}
