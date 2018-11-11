#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 10086
char ans[MAXN],str[MAXN];

int main()
{
	long m,l,r,k,i,j,len,pos;
	cin>>ans;
	cin>>m;
	while (m--)
	{
		cin>>l>>r>>k;
		len=r-l+1;
		k%=len;
		for (i=l-1;i<=r-1;i++)
		{
			pos=(i-l+1+k)%len+l-1;
			str[pos]=ans[i];
		}
		for (i=l-1;i<=r-1;i++)
			ans[i]=str[i];
	}
	cout<<ans<<endl;
	return 0;
}
