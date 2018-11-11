#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	long i,j,k,x1,y1,x2,y2,dx,dy;
	char a[1];
	cin>>a;
	x1=a[0]+1-'a';
	y1=a[1]-'0';
	cin>>a;
	x2=a[0]+1-'a';
	y2=a[1]-'0';
	cout<<max(abs(x1-x2),abs(y1-y2))<<endl;
	dx=x1-x2;
	dy=y1-y2;
	k=max(abs(dx),abs(dy));
	while (k--)
	{
		if (dx>0)
		{
			cout<<'L';
			dx--;
		}
		if (dx<0)
		{
			cout<<'R';
			dx++;
		}
		if (dy>0)
		{
			cout<<'D';
			dy--;
		}
		if (dy<0)
		{
			cout<<'U';
			dy++;
		}
		cout<<endl;
	}
	return 0;
}
