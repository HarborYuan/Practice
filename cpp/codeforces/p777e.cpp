#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

struct node
{
	long a,b,h;
};
node t[100005];

int cmp(node x,node y)
{
	if (x.b==y.b)
		return x.a>y.a;
	return x.b>y.b;
}

int main()
{
	long n,i,j,k;
	std::ios::sync_with_stdio(false);
	cin>>n;
	for (i=0;i<n;i++)
		cin>>t[i].a>>t[i].b>>t[i].h;
	sort(t,t+n,cmp);
	stack<node> s;
	s.push(t[0]);
	long long sum=t[0].h,ans=t[0].h;
	for (i=1;i<n;i++)
	{
		while (!s.empty()&&t[i].b<=s.top().a)
		{
			sum-=s.top().h;
			s.pop();
		}
		sum+=t[i].h;
		ans=max(ans,sum);
		s.push(t[i]);
	}
	cout<<ans<<endl;
	return 0;
}
