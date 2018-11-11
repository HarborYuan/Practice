#include <iostream>
using namespace std;

int main()
{
	long n,m;
	cin>>n>>m;
	if (n==1&&m==1)
	{
		cout<<0;
		return 0;
	}
	if (n==1||m==1)
	{
		cout<<-1<<endl;
		return 0;
	}
	if (n==2||m==2)
	{
		if (n==2)
		{
			if ((m-1)%4==0)
			{
				cout<<0;
				return 0;
			}
			cout<<-1;
			return 0;
		}
		if (m==2)
		{
			if ((n-1)%4==0)
			{
				cout<<0;
				return 0;
			}
			cout<<-1;
			return 0;
		}
	}
	if ((n+m)%2==0)
		cout<<0;
	else
		cout<<1;
	return 0;
}
