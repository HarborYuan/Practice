#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	long n,map[10],i;
	string a;
	getline(cin,a);
	while (getline(cin,a))
	{
		long m={0};
		istringstream items(a);
		while (items>>map[m])
			m++;
		if (m==0)
			return 0;
		sort(map,map+m);
		long ans={100000000};
		do
		{
			long an1={0},an2={0};
			if (map[0]==0 || map[m/2]==0)
				continue;
			for (i=0;i<(m/2);i++)
				an1=an1*10+map[i];
			for (i=m/2;i<m;i++)
				an2=an2*10+map[i];
			ans=min(abs(an1-an2),ans);
		}while(next_permutation(map,map+m));
		cout<<ans<<endl;
	}
	return 0;
}
