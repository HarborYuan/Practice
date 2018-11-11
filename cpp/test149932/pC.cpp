#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	long n,m;
	while (cin>>n>>m)
	{
		cout<<__gcd(n,m)<<' '<<(long long)n*m/__gcd(n,m)<<endl;
	}
}
