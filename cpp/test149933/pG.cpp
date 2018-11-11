#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;
typedef long long LL;
#define p 1000000007
LL n,m;
long cc[5000][5000];

LL quick_mod(LL a, LL b)
{
    LL ans = 1;
    a %= p;
    while(b)
    {
        if(b & 1)
        {
            ans = ans * a % p;
            b--;
        }
        b >>= 1;
        a = a * a % p;
    }
    return ans;
}

LL C(LL n, LL m)
{
    if(m > n) return 0;
    LL ans = 1;
    for(int i=1; i<=m; i++)
    {
        LL a = (n + i - m) % p;
        LL b = i % p;
        ans = ans * (a * quick_mod(b, p-2) % p) % p;
    }
    return ans;
}

LL Lucas(LL n, LL m)
{
    if(m == 0) return 1;
    if (n%p<5000 && m%p<5000)
    {
    	if (cc[n%p][m%p]==-1)
    	{
    		cc[n%p][m%p]=C(n%p,m%p);
		}
		return cc[n%p][m%p]* Lucas(n / p, m / p) % p;
	}
    return C(n % p, m % p) * Lucas(n / p, m / p) % p;
}

int main()
{
	memset(cc,-1,sizeof(cc));
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%I64d%I64d", &n, &m);
        printf("%I64d\n", Lucas(m+n,min(m,n)));
    }
    return 0;
}
