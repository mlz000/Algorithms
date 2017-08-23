#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=101;
int a[N];
int main()
{
      int i,j,n,k;
      scanf("%d%d",&n,&k);
      if(n==1 && k==1) printf("1\n"); 
      else 
      {
          a[1]=2;a[2]=4;
          {
                 if(k>n/2) k=n+1-k;
                 a[k]=2*k;
          }
          printf("%d\n",a[k]);
      }
      return 0;
}
