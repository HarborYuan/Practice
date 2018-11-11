#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

bool a[100010];

int main()
{
	ios::sync_with_stdio(false);
	long n,i,j,k,now;
	memset(a,false,sizeof(a));
	cin>>n;
	now=n;
	for (i=1;i<=n;i++)
	{
		cin>>k;
		a[k]=true;
		if (k==now)
		{
			while (a[now])
			{
				cout<<now<<' ';
				now--;
			}
		}
		cout<<endl;
	}
	return 0;
}
