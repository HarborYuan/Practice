#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a[5][5];

int main()
{
	char c;
	memset(a, 0, sizeof(a));
	for(int i=1; i<=4; i++)
		for(int j=1; j<=4; j++)
		{
			c = getchar();
			while(c == '\n') c = getchar();
			if(c == '+')
			{
				for(int k=1; k<=4; k++)
				{
					a[i][k]++;
					a[k][j]++;
				}
				a[i][j]--;
			}
		}
	int sum = 0;
	for(int i=1; i<=4; i++)
		for(int j=1; j<=4; j++)
			sum += a[i][j]%2;
	printf("%d\n", sum);
	for(int i=1; i<=4; i++)
		for(int j=1; j<=4; j++)
			if(a[i][j]%2)
				printf("%d %d\n", i, j);
	return 0;
} 
