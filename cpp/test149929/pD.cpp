#include <iostream>
#include <cmath>
using namespace std;

#define MAXV 102
#define INF 1000000000

long map[MAXV][MAXV],n;

int prime()
{
	long i,j,d[MAXV],vis[MAXV],mint,v;
	for(i=1;i<=n;i++)
	{
		d[i]=map[1][i];
		vis[i]=0;
	}
	for (i=1;i<=n;i++)
	{
		mint=INF;
		for (j=1;j<=n;j++)
			if(!vis[j] && d[j]<mint)
			{
				mint=d[j];
				v=j;
			}
		vis[v]=1;
		for (j=1;j<=n;j++)
			if(!vis[j] && d[j]>map[v][j])
				d[j]=map[v][j];
	}
	for (d[0]=0,i=1;i<=n;i++)
		d[0]+=d[i];
	return d[0];
}

int main()
{
	long i,j;
	while(cin>>n){
	for (i=1;i<=n;i++)
		for (j=1;j<=n;j++)
			cin>>map[i][j];
	cout<<prime()<<endl;}
	return 0;
}
