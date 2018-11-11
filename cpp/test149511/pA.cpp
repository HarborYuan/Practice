#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int a[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	int m,d;
	cin>>m>>d;
	cout<<ceil((a[m-1]-(8-d))/float(7))+1<<endl;
	return 0;
 } 
