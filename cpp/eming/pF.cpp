#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

long map[10][10];
set<int> x[10],y[10],z[10];
long fan,i,j,num;
bool xxx=false;

void print()
{
	for (i=1;i<=9;i++)
	{
		for (j=1;j<=9;j++)
			cout<<map[i][j]<<' ';
		cout<<endl;
	}
	cout<<endl;
}

void dfs(long kx,long ky)
{
	if (xxx)
		return;
	long i,fan;
	if (ky==10)
		{
		if (kx==9)
		{
			print();
			xxx=true;
			return;
		}
		else
		{
			kx++;
			ky=1;
		}
		}
	fan=((ky-1)/3)+1+(((kx-1)/3))*3;
	if (map[kx][ky]!=0)
	{
		dfs(kx,ky+1);
		return;
	}
	for (i=1;i<=9;i++)
		if (!(x[kx].count(i))&&!(y[ky].count(i))&&!(z[fan].count(i)))
		{
			x[kx].insert(i);
			y[ky].insert(i);
			z[fan].insert(i);
			map[kx][ky]=i;
			dfs(kx,ky+1);
			map[kx][ky]=0;
			x[kx].erase(i);
			y[ky].erase(i);
			z[fan].erase(i);
		}
}
int main()
{
	for (i=1;i<=9;i++)
		for (j=1;j<=9;j++)
		{
			cin>>map[i][j];
			fan=((j-1)/3)+1+((i-1)/3)*3;
			x[i].insert(map[i][j]);
			y[j].insert(map[i][j]);
			z[fan].insert(map[i][j]);
		}
	num=0;
	dfs(1,1);
	return 0;
}
