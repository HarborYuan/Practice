#include <iostream>
#include <cmath> 
using namespace std;

int main()
{
	long n,i,c;
	float a,b;
	cin>>n;
	for (i=0;i<n;i++)
	{
		cin>>a>>b;
		c=ceil((pow(a,2)+pow(b,2))*3.14159/100);
		printf("Property %d: This property will begin eroding in year %d.\n",i+1,c);
	}
	printf("END OF OUTPUT.\n");
	return 0;
}
