#include <iostream>
using namespace std;

int saturating_add(int x,int y)
{
	int w=sizeof(int)*8;
	int ans=x+y;
	int anst=x+y;
	x>>=(w-1);
	y>>=(w-1);
	ans>>=(w-1);
	int min=1<<(w-1);
	int max=min-1;
	int zh=x&y&~ans;
	int fu=~x&~y&ans;
	(zh&&(anst=min))||(fu&&(anst=max));
	return anst;
}

int main()
{
	int x,y;
	cin>>x>>y;
	cout<<saturating_add(x,y)<<endl;
 } 
