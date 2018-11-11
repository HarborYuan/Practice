#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
long map2[1010][1010],map5[1010][1010],dp2[1010][1010],dp5[1010][1010];
char pos2[1010][1010],pos5[1010][1010];

void ou2(long x,long y)
{
	if (x==1 && y==1)
		return;
	if (pos2[x][y]=='D')
	{
		ou2(x-1,y);
		cout<<'D';
	}
	if (pos2[x][y]=='R')
	{
		ou2(x,y-1);
		cout<<'R';
	}
}

void ou5(long x,long y)
{
	if (x==1 && y==1)
		return;
	if (pos5[x][y]=='D')
	{
		ou5(x-1,y);
		cout<<'D';
	}
	if (pos5[x][y]=='R')
	{
		ou5(x,y-1);
		cout<<'R';
	}
}

int main()
{
	ios::sync_with_stdio(false);
	long n,i,j,k,ii,x=-1,y=-1,ans,flag=0;
	cin>>n;
	for (i=1;i<=n;i++)
	for (j=1;j<=n;j++)
	{
		cin>>k;
		if (k==0)
		{
			flag++;
			x=i;
			y=j;
			map2[i][j]=2147483640/2;
			map5[i][j]=2147483640/2;
		}
		long iii=1;
		for (ii=1;ii<=k/2;ii++)
			if (k%(iii*=2)!=0)
				break;
		map2[i][j]=ii-1;
		iii=1;
		for (ii=1;ii<=k/5;ii++)
			if (k%(iii*=5)!=0)
				break;
		map5[i][j]=ii-1;
	}
	memset(dp2,0x7f,sizeof(dp2));
	dp2[1][1]=map2[1][1];
	memset(dp5,0x7f,sizeof(dp5));
	dp5[1][1]=map5[1][1];
	for (i=1;i<=n;i++)
		for (j=1;j<=n;j++)
			if (!(i==1 && j==1))
			{
				dp2[i][j]=min(dp2[i-1][j],dp2[i][j-1])+map2[i][j];
				if (i-1>0 && dp2[i-1][j]<dp2[i][j-1])
					pos2[i][j]='D';
				else
					pos2[i][j]='R';
				dp5[i][j]=min(dp5[i-1][j],dp5[i][j-1])+map5[i][j];
				if (i-1>0 && dp5[i-1][j]<dp5[i][j-1])
					pos5[i][j]='D';
				else
					pos5[i][j]='R';
			}
	ans=min(dp2[n][n],dp5[n][n]);
	if(flag && ans>=1)
	{
		cout<<1<<endl;
		for (i=1;i<=x-1;i++)
			cout<<'D';
		for (i=1;i<=n-1;i++)
			cout<<'R';
		for (i=x;i<=n-1;i++)
			cout<<'D';
		return 0;
	}
	cout<<ans<<endl;
	if (dp2[n][n]<dp5[n][n])
		ou2(n,n);
	else
		ou5(n,n);
	return 0;
 } 
