#include <iostream>
using namespace std;

int xbyte(unsigned word,int bytenum)
{
	return int(word)<<(24-(bytenum<<3))>>24;
} 
 
 int main()
 {
 	long x,y;
 	cin>>x>>y;
 	cout<<xbyte(x,y);
 }
