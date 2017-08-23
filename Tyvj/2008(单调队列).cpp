#include<cstdio> //f[i]表示1~i刚才落在顶层最短长度 
#include<iostream>
#include<algorithm> 
using namespace std; 
const int N=200005;
int a[N],q[N],g[N];
long long sum[N],f[N]; 
int main()
{
      int i,j,n; 
      scanf("%d",&n);
      for(i=1;i<=n;++i)
      {
          scanf("%d",&a[i]);
          sum[i]=sum[i-1]+a[i];
      } 
      int h,t;
      h=t=0; 
      for(i=1;i<=n;++i)
      {
        while(h<t && sum[i]-sum[q[h+1]]>=f[q[h+1]]) h++; 
        f[i]=sum[i]-sum[q[h]]; 
        g[i]=g[q[h]]+1; 
        while(h<t && f[i]+sum[i]<=f[q[t]]+sum[q[t]]) --t; 
        q[++t]=i; 
      }  
      printf("%d",n-g[n]); 
    //  system("pause");  
      return 0; 
} 

