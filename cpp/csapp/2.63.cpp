#include <iostream>
using namespace std;

unsigned srl(unsigned x, int k)
{
	unsigned xsra=(int)x>>k;
	if ((int)x>=0)
		return xsra;
	unsigned ans=0;
	int w=8*sizeof(int);
	for (int i=w-1;i>=w-k;i--)
	{
		ans=ans|(1<<i);
	}
	return ~ans&xsra;
 } 
 
 int sra(int x,int k)
 {
 	int xsrl=(unsigned) x>>k;
 	if (x>=0)
 		return xsrl;
 	int ans=0;
 	int w=8*sizeof(int);
 	for (int i=w-1;i>=w-k;i--)
 	{
 		ans=ans|(1<<i);
	}
	return ans|xsrl;
 }
 int main()
 {
 	int x,k;
 	cin>>x>>k;
 	cout<<sra(x,k)<<endl<<(x>>k)<<endl;
 }
