#include <iostream>
#include <cstring> 
using namespace std;
char a[100000],b[100000];
long an[10000][10000];
int main()
{
	long la,lb,i,j,max;
	cin>>a>>b;
	la=strlen(a);
	lb=strlen(b);
	max=0; 
	memset(an,sizeof(an),0);
	for (i=1;i<=la;i++)
		for (j=1;j<=lb;j++)
		{
			if (a[i-1]==b[j-1])
			{
				an[i][j]=an[i-1][j-1]+1;
				if (an[i][j]>max)
					max=an[i][j];
			}			
			else
				an[i][j]=0;
		}
	cout<<max<<endl;
	return 0;
 } 
