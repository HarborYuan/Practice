#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
long map[20][20];
long tea[10];
long tu[255][255];
int main()
{
	long n,m,x,y,i,j,k,point,pu,pd,pl,pr;
	while(cin>>n>>m)
	{
		for (i=1;i<=m;i++)
		{
			cin>>x>>y;
			tea[i]=n*(x-1)+y;
		}
		for (i=1;i<=n*n;i++)
			for (j=1;j<=n*n;j++)
				tu[i][j]=0x7f7f7f7f>>1;
		for (i=1;i<=n;i++)
			for (j=1;j<=n;j++)
			{
				cin>>map[i][j];
				point=n*(i-1)+j;//1..n^2
				pu=pd=pl=pr=-1;
				if (i-1>0)
					pu=n*(i-2)+j;
				if (i+1<=n)
					pd=n*(i)+j;
				if (j-1>0)
					pl=point-1;
				if(j+1<=n)
					pr=point+1;
				if (pu>0)
					tu[point][pu]=map[i][j];
				if (pd>0)
					tu[point][pd]=map[i][j];
				if (pl>0)
					tu[point][pl]=map[i][j];
				if (pr>0)
					tu[point][pr]=map[i][j];
			}
		for (i=1;i<=n*n;i++)
			tu[i][i]=0;
		for (k=1;k<=n*n;k++)
			for (i=1;i<=n*n;i++)
				for (j=1;j<=n*n;j++)
					tu[i][j]=min(tu[i][j],tu[i][k]+tu[k][j]);
		long mint=0x7f7f7f7f;
		for (i=1;i<=n*n;i++)
		{
			long anst=0;
			for (j=1;j<=m;j++)
				anst+=tu[tea[j]][i];
			mint=min(anst,mint);
		}
		cout<<mint<<endl;
	}
	return 0;
}
