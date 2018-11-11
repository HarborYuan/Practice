#include <iostream>
using namespace std;

int func4(int a,int b)
{
	if (a<=0)
		return 0;
	if (a==1)
		return b;
	return func4(a-1,b)+func4(a-2,b)+b;
 } 
 
int main()
{
	int a=8;
	int b;
	for (b=2;b<=4;b++)
	cout<<func4(a,b)<<' '<<b<<endl;
	
}
