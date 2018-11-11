#include <iostream>
#include <cmath>
using namespace std;

bool map[65536];
long team[65536];
long head,tail,now;
long con[16]={0xc800,0xe400,0x7200,0x3100,0x8c80,0x4e40,0x2720,0x1310,0x08c8,0x04e4,0x0272,0x0131,0x008c,0x004e,0x0027,0x0013};


int main()
{
	long i,j,t,step;
	long des1=0xffff;
	long des2=0x0000;
	char x;
	for (i=0;i<65536;i++)
		map[i]=false;
	now=0;
	for (i=0;i<16;i++)
	{
		while (true)
		{
			cin>>x;
			if ((x=='w') || (x='b'))
				break;
		}
		if (x=='w')
			now+=pow(2,15-i);
	}
	if ((des1==now) || (des2==now))
	{
		cout<<0;
		return 0;
	}
	head=0;
	tail=1;
	t=1;
	step=1;
	team[1]=now;
	map[now]=true;
	do
	{
		head++;
		for (i=0;i<16;i++)
		{
			now=con[i]^team[head];
			if ((des1==now) || (des2==now))
			{
				cout<<step<<endl;
				return 0; 
			}
			if (!map[now])
			{
				tail++;
				team[tail]=now;
				map[now]=true;
			}
		}
		if (head==t)
		{
			step++;
			t=tail;
		}
	}
	while (head<=tail);
	cout<<"Impossible\n";
	return 0;
 } 
