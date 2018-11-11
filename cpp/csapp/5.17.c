#include <stdio.h>
#include <time.h>

char demo[100000005];

void *basic_memset1(void *s,int c,size_t n)
{
	size_t cnt=0;
	unsigned char *schar=s;
	while (cnt<n)
	{
		*schar++=(unsigned char) c;
		cnt++;
	}
	return s;
} 

void *basic_memset2(void *s,int c,size_t n)
{
	size_t cnt=0;
	unsigned long *slong=s;
	if (n>=8)
	{
		unsigned long c1=0;
		cnt=8;
		while (cnt--)
			c1=(c1<<8)+(unsigned char)c;
		size_t n1=n-7;
		cnt=0;
		while (cnt<n1)
		{
			*(slong++)=c1;
			cnt+=8;
		}
	}
	unsigned char *schar=(unsigned char *)slong;
	while (cnt<n)
	{
		*schar++=(unsigned char) c;
		cnt++;
	}
	return s;
} 

int main()
{
	clock_t start,finish;
	int i;
	start=clock();
	for (i=1;i<=10;i++)
		basic_memset2(demo,15,8);
	finish=clock();
	for (i=0;i<=20;i++)
		printf("%d\n",demo[i]);
	printf("%d",finish-start);
	return 0;
}
