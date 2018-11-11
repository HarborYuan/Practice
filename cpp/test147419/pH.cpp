#include<cstdio>
#include<iostream>
using namespace std;

int main(){
	int b1,b2,b3,b4,b5,b6,n,n1,n2;
	int b[4]={0,5,3,1};
	while(scanf("%d%d%d%d%d%d",&b1,&b2,&b3,&b4,&b5,&b6)!=EOF)
	{
		if(b1==0&&b2==0&&b3==0&&b4==0&&b5==0&&b6==0)
			break;
		n=b6+b5+b4+(b3+3)/4;
		n2=5*b4+b[b3%4];
		if(b2>n2)
			n+=(b2-n2+8)/9;
		n1=36*(n-b6)-25*b5-16*b4-9*b3-4*b2;
		if(b1>n1)
			n+=(b1-n1+35)/36;
		printf("%d\n",n);
	}
	return 0;
}
