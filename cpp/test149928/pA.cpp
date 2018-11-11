#include <iostream>
#include <cstring>
using namespace std;

bool map2[22][22];
long map[22][22];

void dfs(long x,long y)
{
	if (map[x+1][y]==1 && map2[x+1][y]==true)
	{
		map2[x+1][y]=false;
		dfs(x+1,y);
	} 
	if (map[x-1][y]==1 && map2[x-1][y]==true)
	{
		map2[x-1][y]=false;
		dfs(x-1,y);
	} 
	if (map[x][y+1]==1 && map2[x][y+1]==true)
	{
		map2[x][y+1]=false;
		dfs(x,y+1);
	} 
	if (map[x][y-1]==1 && map2[x][y-1]==true)
	{
		map2[x][y-1]=false;
		dfs(x,y-1);
	} 
}

int main()
{
	long m,n,num,x,y,i,j,ans;
	char xx;
	while(cin>>m>>n){
	if (m==0 && n==0)
		return 0;
	ans=0;
	for (i=0;i<=n+1;i++)
		for (j=0;j<=m+1;j++)
		{
			map[i][j]=0;
			map2[i][j]=true;
		}
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
		{
			do
				cin>>xx;
			while (!(xx=='.' || xx=='#' || xx=='@'));
			if (xx=='.')
				map[i][j]=1;
			if (xx=='#')
				map[i][j]=0;
			if (xx=='@')
			{
				x=i; y=j; map[i][j]=1; map2[i][j]=false;
			}
		}
	dfs(x,y);
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
			if (map2[i][j]==false)
				ans++;
	cout<<ans<<endl;}
	return 0;
 } 
