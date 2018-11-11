#include <iostream>
using namespace std;

void jisort(int a[],int n)
{
	int b[n];
	for (int i=0;i<n;i++)
	{
		int ans=0;
		for (int j=0;j<n;j++)
		{
			if (a[j]<a[i])
				ans++;
		}
		b[ans]=a[i];
	}
	for (int i=0;i<n;i++)
		a[i]=b[i];
 }
 
int main()
{
	int n=10;
	int a[n]={10,2,3,5,6,1,8,7,4,9};
	jisort(a,n);
	for (int i=0;i<n;i++)
		cout<<a[i]<<' ';
	cout<<endl;
}
