#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

struct stra
{
	long begin,end;
};

int cmp(const stra &a,const stra &b)
{
	if (a.begin==b.begin)
		return a.end<b.end;
	return a.begin<b.begin;
}
stra a[25003];

int main()
{
	ios::sync_with_stdio(false);
	long n,t,i,j,k;
	cin>>n>>t;
	for (i=1;i<=n;i++)
	{
		scanf("%d %d",&a[i].begin,&a[i].end);
	}
	sort(a,a+n,cmp);
	long ans=0,tailn=1,tailt=0;
	while (tailt<t)
	{
		long next=tailt+1;
		for (i=tailn;i<=n;i++)
			if (a[i].begin<=next && a[i].end>=next)
				tailt=max(tailt,a[i].end);
			else if (a[i].begin>next) 
			{
				tailn=i;
				break;
			}
		if (next==tailn+1)
			{
				cout<<-1<<endl;
				return 0;
			}
		ans++;
	}
	cout<<ans<<endl;
}
