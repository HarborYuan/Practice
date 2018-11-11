#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

char ans[100010],str[100010];

int main()
{
	long i,j,n;
	cin>>n;
	cin>>ans;
	for (i=1;i<n;i++)
	{
		cin>>str;
		long len=strlen(str);
		for (j=0;j<=len-1;j++)
		{
			if (ans[j]==str[j])
				continue;
			if (ans[j]=='?')
			{
				ans[j]=str[j];
				continue;
			}
			if (str[j]=='?')
				continue;
			ans[j]='+';
		}
		ans[len]='\0';
	}
	long len=strlen(ans);
	for (j=0;j<=len-1;j++)
	{
		if (ans[j]=='+')
		{
			cout<<'?';
			continue;
		}
		if (ans[j]=='?')
		{
			cout<<'x';
			continue;
		}
		cout<<ans[j];
	}
	cout<<endl;
	return 0;
}
