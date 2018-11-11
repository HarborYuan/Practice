#include <iostream>
#include <cstring>
#define MAX 1000000
using namespace std;

long pri[MAX];

void make_pri() {
    memset(pri,0,sizeof(pri));
    for(int i = 2;i < MAX;i++) {
        if(pri[i]) continue;
        for(int j=i+i;j<MAX;j+=i)   
			pri[j]=1;
    }
}

int main() 
{
    long n;
    make_pri();
    while(cin>>n) {
        int sum=0;
        for(int i = 2;i <= n;i++)
            if(!pri[i]) 
				sum++;
        cout<<sum<<endl;
    }
    return 0;
}
