#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(long a,long b)
{
  return a>b; 
}
int main()
{
	long a[10],i;
	for (i=0;i<10;i++)
	{
		cin>>a[i];
	}
	sort(a,a+10,cmp);
	cout<<a[0]<<endl<<a[1]<<endl<<a[2]<<endl;
	return 0;
 } 
