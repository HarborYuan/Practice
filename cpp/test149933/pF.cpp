#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define N 1001

char map[N][N];
long ans,id=0,n,m;
long pos[N][N],answer[N*N];
const int dx[]={-1,0,1,0},dy[]={0,-1,0,1};

void dfs(long x,long y)
{
	long i,nx,ny;
	pos[x][y]=id;
	for (i=0;i<=3;i++)
	{
		nx=x+dx[i];
		ny=y+dy[i];
		if (0<nx && nx<=n &&0<ny&&ny<=m&&!pos[nx][ny])
			if (map[nx][ny]=='*')
				ans++;
			else
				dfs(nx,ny);
	}
}

int main()
{
	long i,j,x,y,k;
	cin>>n>>m>>k;
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
			while (cin>>map[i][j] && map[i][j]!='.'&&map[i][j]!='*');
	memset(pos,0,sizeof(pos));
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
			if (map[i][j]=='.'&&!pos[i][j])
			{
				ans=0;
				id++;
				dfs(i,j);
				answer[id]=ans;
			}
	while(k--)
	{
		cin>>x>>y;
		cout<<answer[pos[x][y]]<<endl;
	}
	return 0;
}
