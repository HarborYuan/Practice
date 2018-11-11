#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

struct gunlist{
	int price;
	int numpei;
	int pei[1005];
};

map<int,double> peimap;
gunlist gun[1005];

void sort(int begin,int end)
{
	for (int i=begin;i<end;i+=1000){
		double maxx = 0;
		int maxj=-1;
		for (int j=i;j<=end;j+=1000){
			if (peimap.find(j)->second>maxx){
				maxj=j;
				maxx=peimap.find(j)->second;
			}
		}
		peimap[maxj]=peimap.find(i)->second;
		peimap[i]=maxx;
	}
}

int main()
{
	int n,m;
	cin>>n>>m;
	for (int i = 0; i<n;i++)
	{
		int price,k;
		cin >> price>>k;
		gun[i].price = price;
		gun[i].numpei = k;
		for (int j=0;j<k;j++)
			cin>>gun[i].pei[j];
	}
	for (int i=0;i<m;i++)
	{
		int q;
		double b;
		cin>>q>>b;
		if (peimap.find(q)!=peimap.end())
		{
			int qq=q+1000;
			while (peimap.find(qq)!=peimap.end())
				qq+=1000;
			peimap[qq]=b;
			sort(q,qq);
		}
		else
			peimap[q]=b;
	}
	double ans = 0;
	for (int i=0;i<n;i++)
	{
		double number = gun[i].price;
		double answer = number;
		int flag[1005]={0};
		for (int j=0;j<gun[i].numpei;j++)
		{
			answer += number*peimap.find(gun[i].pei[j]+flag[gun[i].pei[j]]*1000)->second;
			flag[gun[i].pei[j]]++;
		}
		if (answer > ans)
			ans = answer;
	}
	cout.precision(4);
	cout<<fixed<<ans<<endl;
	return 0;
}
