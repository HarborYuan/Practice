#include <iostream>
#include <cmath>
using namespace std;

long map[7][7],ans;
bool answer[1000000];

void dfs(long i,long j,long z)
{
	if (z==6)
	{
		answer[ans]=true;
		return;
	}
	long xxx;
	if (map[i+1][j]!=-1)
		{
			xxx=ans;
			ans=ans*10+map[i+1][j];
			dfs(i+1,j,z+1);
			ans=xxx;
		}
	if (map[i-1][j]!=-1)
		{
			xxx=ans;
			ans=ans*10+map[i-1][j];
			dfs(i-1,j,z+1);
			ans=xxx;
		}
	if (map[i][j+1]!=-1)
		{
			xxx=ans;
			ans=ans*10+map[i][j+1];
			dfs(i,j+1,z+1);
			ans=xxx;
		}
	if (map[i][j-1]!=-1)
		{
			xxx=ans;
			ans=ans*10+map[i][j-1];
			dfs(i,j-1,z+1);
			ans=xxx;
		}
}

int main()
{
	long  i,j;
	for (i=0;i<=6;i++)
		for (j=0;j<=6;j++)
			map[i][j]=-1;
	for (i=1;i<6;i++)
		for (j=1;j<6;j++)
			cin>>map[i][j];
	for (i=0;i<1000000;i++)
		answer[i]=false;
	for (i=1;i<6;i++)
		for (j=1;j<6;j++)
		{
			ans=map[i][j];
			dfs(i,j,1);
		}
	long ss={0};
	for (i=0;i<1000000;i++)
		if (answer[i]==true)
			{
				ss++;
		}
	cout<<ss<<endl;
	return 0;
}
