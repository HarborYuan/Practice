#include <iostream>
#include <map>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
int score[1010];
map<string, int> p1,p2;
string name[1010];

int main()
{
	long n,i,j,ans=0;
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>name[i]>>score[i];
		p1[name[i]]+=score[i];
	}
	for (i=1;i<=n;i++)
	{
		if (p1[name[i]]>ans)
			ans=p1[name[i]];
	}
	for (i=1;i<=n;i++)
	{
		p2[name[i]]+=score[i];
		if (p2[name[i]]>=ans && p1[name[i]]==ans)
		{
			cout<<name[i]<<endl;
			return 0;
		}
	}
 } 
