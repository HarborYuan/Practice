#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

long map[1010][1010];
long dis[1010];
bool flag[1010];
long a[1010];
long ans[1010];
long n;

long spfa(long s)
{
	queue<int> q;
	q.push(s);
	dis[s]=0;
	a[s]++;
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
						return -1;
				}
			}
		}
	}
}

long spfa2(long s)
{
	queue<int> q;
	q.push(s);
	dis[s]=0;
	a[s]++;
	long head;
	while (!q.empty())
	{
		head=q.front();
		q.pop();
		flag[head]=false;
		for (long i=1;i<=n;i++)
		{
			if (dis[i]>dis[head]+map[i][head])
			{
				dis[i]=dis[head]+map[i][head];
				if (!flag[i])
				{
					q.push(i);
					flag[i]=true;
					a[i]++;
					if (a[i]>=n)
						return -1;
				}
			}
		}
	}
}
void re()
{
    memset(dis,0x7f,sizeof(dis));
    memset(flag,false,sizeof(flag));
    memset(a,0,sizeof(a));
}
int main()
{
	long m,x,i,j;
	long ai,bi,ti;
	cin>>n>>m>>x;
	memset(map,0x7f,sizeof(map));
	for (i=1;i<=m;i++)
	{
		cin>>ai>>bi>>ti;
		map[ai][bi]=min(map[ai][bi],ti);
	}
	memset(ans,0,sizeof(ans));
	re();
	spfa(x);
	for (i=1;i<=n;i++)
	{
		ans[i]+=dis[i];
	}
	re();
	spfa2(x);
	for (i=1;i<=n;i++)
	{
		ans[i]+=dis[i];
	}
	long maxt={0};
	for (i=1;i<=n;i++)
		maxt=max(maxt,ans[i]);
	cout<<maxt;
	return 0;
}
