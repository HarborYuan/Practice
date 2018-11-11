#include <iostream>
#include <algorithm> 
using namespace std;

int main()
{
	long n,m,i,j,r,l,mint;
	cin>>n>>m;
	mint=0x7f7f7f7f;
	cout<<mint<<endl;
	for (i=1;i<=m;i++)
	{
		cin>>l>>r;
		mint=min(mint,abs(r-l)+1);
	}
	cout<<mint<<endl;
	for (i=0;i<n;i++)
		cout<<i%mint<<' ';
	cout<<endl;
	return 0;
}
