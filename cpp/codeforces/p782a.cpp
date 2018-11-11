#include <iostream>
#include <set>
using namespace std;
set<int> a;
int main()
{
	long n,i,j,k,ans,maxt;
	cin>>n;
	maxt=0;
	ans=0;
	for (i=1;i<=2*n;i++)
	{
		cin>>k;
		if (a.count(k))
		{
			ans--;
			a.erase(k);
		}
		else
		{
			ans++;
			a.insert(k);
			if (maxt<ans)
				maxt=ans;
		}
	 }
	cout<<maxt<<endl;
	return 0; 
 } 
