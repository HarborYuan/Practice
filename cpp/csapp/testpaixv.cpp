#include <iostream>
#include <cstdio>
using namespace std;

void fun(int a[],int n)
{   int i,j,gap,tmp; 
       gap=n/3;
       while(true)
       {     for (i=gap;i<n;i++)
              {     tmp=a[i];
                     j=i-gap;
                     while(j>=0 && tmp<a[j])
                     {     a[j+gap]=a[j];
                            j=j-gap;
                     }
                     a[j+gap]=tmp;
              }
              for (i=0;i<n;i++)
                cout<<a[i]<<' ';
			  cout<<endl; 
              if(gap==1) break;
              else if (gap<3) gap=1;
              else gap=gap/3;
       }
}

int main()
{
	int a[]={5,1,3,6,2,7,4,8};
	fun(a,8); 
	
}
