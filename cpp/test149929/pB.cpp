#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

long map[510][510];
long dis[510];
bool flag[510];
long a[510];

bool spfa(long n)
{
	queue<int> q;
	q.push(1);
	dis[1]=0;
	a[1]++;
	long head;
	while (!q.empty())
	{
		head=q.front();
		q.pop();
		flag[head]=false;
		for (long i=1;i<=n;i++)
		{
			if (dis[i]>dis[head]+map[head][i])
			{
				dis[i]=dis[head]+map[head][i];
				if (!flag[i])
				{
					q.push(i);
					flag[i]=true;
					a[i]++;
					if (a[i]>=n)
						return true;
				}
			}
		}
	}
	return false;
}

void re()
{
	memset(map,0x7f,sizeof(map));
    memset(dis,0x7f,sizeof(dis));
    memset(flag,false,sizeof(flag));
    memset(a,0,sizeof(a));

}
int main()
{
	long f;
	cin>>f;
	long n,m,w;
	long s,e,t;
	long i;
	while (f--)
	{
		re();
		cin>>n>>m>>w;
		for (i=0;i<m;i++)
		{
			cin>>s>>e>>t;
			map[s][e]=min(map[s][e],t);
			map[e][s]=min(map[e][s],t);
		}
		for (i=0;i<w;i++)
		{
			cin>>s>>e>>t;
			map[s][e]=min(map[s][e],-t);
		}
		if (spfa(n))
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}
