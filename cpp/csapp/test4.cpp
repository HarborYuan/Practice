#include<iostream>
using namespace std;
int tree[16]={0,36,8,50,6,22,45,107,1,7,20,35,40,47,99,1001};

int func7(int index,int num)
{
	if (index>=16)
		return -1;
	if (num<tree[index])
		return 2*func7(index*2,num);
	if (num==tree[index])
		return 0;
	return 2*func7(index*2+1,num)+1;
}

int main()
{
	for (int j=0;j<=7;j++)
		for (int i=0;i<=1001;i++)
			if (func7(1,i)==j)
				cout<<j<<' '<<i<<endl;
	return 0;
 } 
