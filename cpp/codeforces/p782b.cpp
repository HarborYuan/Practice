#include <iostream>
#include <vector>
using namespace std;

struct node
{
	vector <int> ii;
};

node a[200009];
bool t[200009];
int team[200009][1];
int answer[200009];

int main()
{
	long n,x,y,i,j,ans;
	cin>>n;
	for (i=1;i<=n-1;i++)
	{
		cin>>x>>y;
		a[x].ii.push_back(y);
		a[y].ii.push_back(x);
	}
	ans=0;
	for (i=1;i<=n;i++)
		if (a[i].ii.size()>ans)
			ans=a[i].ii.size();
	cout<<ans+1<<endl;
	memset(t,true,sizeof(t));
	answer[1]=1;
	long head=0;
	long tail=1;
	team[1][0]=1;
	team[1][1]=0x7f7f7f7f;
	while (head<tail)
	{
		head++;
		for (int i=a[team[head][0]].ii.size()-1;i>=0;i--)
		{
			if (t[team[head][0]])
		}
	}
	return 0;
}
