#include <iostream>
using namespace std;

int main()
{
	long i,j,k;
	float a,s;
	cin>>a;
	while (a!=0)
	{
		i=1;
		s=0;
		while (s+float(1)/(i+1)<a)
		{
			s+=float(1)/(i+1);
			i++;
		}
		printf("%d card(s)\n",i);
		cin>>a;
	}
	return 0;
}
