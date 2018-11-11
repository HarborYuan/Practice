#include <stdio.h>
int main()
{
	int x=3,y=4,z=5;
	x=(x+=y,y=x?x+=z,y+=z:z++),(z=z--,x=++x);
	printf("%d %d %d",x,y,z);
	return 0;
}
