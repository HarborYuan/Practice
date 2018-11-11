#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

long a[100005]={0};
queue<int> q;

int main()
{
	long n,k,i,j,ans(0),tail(0),head;
	cin>>n>>k;
	q.push(n);
	a[n]==1;
	tail=n;
	while (!q.empty())
	{
		head=q.front();
		q.pop();
		if (head==k)
		{
			cout<<ans<<endl;
			return 0;
		}
		if (head*2<=100000 && a[head*2]==0)
		{
			j=head*2;
			q.push(head*2);
			a[head*2]=1;
		}
		if (head+1<=100000 && a[head+1]==0)
		{
			j=head+1;
			q.push(head+1);
			a[head+1]=1;
		}
		if (head-1>=0 && a[head-1]==0)
		{
			j=head-1;
			q.push(head-1);
			a[head-1]=1;
		}
		if (tail==head)
		{
			ans++;
			tail=j;
		}
	}
 } 
