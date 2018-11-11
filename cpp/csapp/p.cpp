#include <iostream>
using namespace std;

unsigned srl(unsigned x,int k)
{
	unsigned xsra=(int)x>>k;
	int w=sizeof(int)*8;
	int ans=((1<<k)-1)<<(w-k);
	return ~ans&xsra;
} 

int sra(int x,int k)
{
	int xsrl=(unsigned)x>>k;
	int w=sizeof(int)*8;
	int m=1<<(w-k-1);
	int ans=m-1; 
	return (ans&xsrl)|(~ans&(~(m&xsrl)+m));
}

int xbyte(unsigned word,int bytenum)
{
	return (int)word<<(24-(bytenum<<3))>>24;
}

int main()
{
	int x;
	int y;
	cin>>x>>y;
	cout<<sra(x,y)<<' '<<(x>>y)<<endl;
	return 0;
}
