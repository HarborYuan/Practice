#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define maxn 1000005
using namespace std;
long m[maxn],n[maxn],w[maxn];
int main()
{
	long a,b,c;
	char ch[10];
	while((scanf("%d%d%d",&a,&b,&c))!=EOF){
		long t;
		scanf("%d",&t);
		long p=0,q=0,r,sum1=0,f;
		long long sum2=0;
		for(int i=0;i<t;i++){
			scanf("%d",&f);
			scanf("%s",ch);
			if(ch[0] == 'U')
			  m[p++]=f;
			else n[q++]=f;
		}
		sort(m,m+p);
		sort(n,n+q);
		long i,j;
		long l=0;
		for(i=0;i<a&&i<p;i++){
			sum2+=m[i];
			sum1++;
		}
		while(m[i]){
			w[l++]=m[i++];
		}
		for(i=0;i<b&&i<q;i++){
			sum2+=n[i];
			sum1++;
		}
		while(n[i])
		   w[l++]=n[i++];
		sort(w,w+l);
		for(int i=0;i<c&&i<l;i++){
			sum2+=w[i];
			sum1++;
		}
		printf("%d %lld\n",sum1,sum2);
	}
	return 0;
}
