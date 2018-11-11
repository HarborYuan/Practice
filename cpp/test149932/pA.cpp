#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

long long a[1000010];
int main()
{
	long long n,k;
	while (cin>>n>>k){
	long long i,ans,answer,ww;
	ans=0;
	for (i=1;i<=(long long)(sqrt(n));i++)
		if (n%i==0)
		{
			a[++ans]=i;
			if (ans==k)
			{
				cout<<i<<endl;
				break;
			}
		}
	answer=k-ans;
	if (answer==0)
		continue;
	if((long long)sqrt(n)*(long long)sqrt(n)==(double)n)
		ans--;
	if (answer>ans)
		cout<<-1<<endl;
	else
		cout<<(long long)(n/a[ans-answer+1])<<endl;
	}
	return 0;
} 
