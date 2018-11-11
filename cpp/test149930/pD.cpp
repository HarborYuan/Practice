#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

long map[100003][1];
int main()
{
	long ax,ay,bx,by,tx,ty;
	long i,j,k,n;
	long mina1,mina2,minb1,minb2;
	double mia1(0),mia2(0),mib1(0),mib2(0),ans(0.0);
	cin>>ax>>ay>>bx>>by>>tx>>ty;
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>map[i][0]>>map[i][1];
		if (pow((map[i][0]-ax),2)+pow((map[i][1]-ay),2)>mia2)
		{
			mina2=i;
			mia2=pow((map[i][0]-ax),2)+pow((map[i][1]-ay),2);
		}
		if (pow((map[mina2][0]-ax),2)+pow((map[mina2][1]-ay),2)>mia1)
		{
			swap(mina2,mina1);
			swap(mia1,mia2);
		}
		if (pow((map[i][0]-bx),2)+pow((map[i][1]-by),2)>mib2)
		{
			minb2=i;
			mib2=pow((map[i][0]-bx),2)+pow((map[i][1]-by),2);
		}
		if (pow((map[minb2][0]-bx),2)+pow((map[minb2][1]-by),2)>mib1)
		{
			swap(minb2,minb1);
			swap(mib1,mib2);
		}
	}
	if (mina1==minb1)
	{
		if (mia1-mia2>=mib1-mib2)
			minb1=minb2;
		else
			mina1=mina2;
	}
	for (i=1;i<=n;i++)
	{
		if (i==mina1)
		{
			ans+=sqrt(pow((map[i][0]-ax),2)+pow((map[i][1]-ay),2))+sqrt(pow((map[i][0]-tx),2)+pow((map[i][1]-ty),2));
			continue;
		}
		if (i==minb1)
		{
			ans+=sqrt(pow((map[i][0]-bx),2)+pow((map[i][1]-by),2))+sqrt(pow((map[i][0]-tx),2)+pow((map[i][1]-ty),2));
			continue;
		}
		ans+=sqrt(pow((map[i][0]-tx),2)+pow((map[i][1]-ty),2))*2;
	}
	cout<<ans<<endl;
}
