#include <iostream>
using namespace std;

int main()
{
	long a;
	bool flag;
	flag=true;
	while (cin>>a)
	{
		if (a==42)
		  flag=false;
		if (flag)
		  cout<<a<<endl;
	}
	return 0;
 } 
