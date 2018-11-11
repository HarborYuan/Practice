#include <iostream>
#include <algorithm>
using namespace std;

char trans(char x)
{
	if (x=='B')
		return 'W';
	return 'B';
}

int main()
{
	long n,m,i,j;
	cin>>n>>m;
	char inin,outt;
	for (i=1;i<=n;i++)
	{
		if (i % 2==0)
			outt='W';
		else
			outt='B';
		for (j=1;j<=m;j++)
		{
			while (true)
			{
				cin>>inin;
				if (inin=='.' || inin=='-')
					break;
			}
			outt=trans(outt);
			if (inin=='.')
				cout<<outt;
			else
				cout<<'-';
		}
		cout<<endl;
	}
 } 
