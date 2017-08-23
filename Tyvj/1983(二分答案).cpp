#include<cstdio> 
#include<iostream>
#include<algorithm>
#include<queue> 
#include<cstring> 
using namespace std; 
const int N=100005;
int a[N]; 
int n,m; 
bool check(int t)
{
    int i; 
    int tt=0;
    int sum=0; 
    for(i=1;i<=n;++i)
    {
      if(a[i]-sum<0) return false; 
      if(a[i]-sum<=m) {sum+=t;}//每人前进sum距离 
      else if(a[i]-sum>m) 
      {
        sum+=a[i]-sum-m; 
        sum+=t; 
      } 
    }  
    return true; 
} 
int main()
{ 
      int l,r,mid,i; 
      scanf("%d%d",&n,&m);
      l=r=0; 
      for(i=1;i<=n;++i)
        scanf("%d",&a[i]); 
      sort(&a[1],&a[n+1]);
      r=a[2]-a[1]+m+1; 
      int ans; 
      while(l<=r)
      {
         if(l==r) break;
         mid=(l+r)>>1;
         if(check(mid)) {ans=mid;l=mid+1;} 
         else r=mid; 
      } 
      printf("%d",ans); 
     // system("pause");  
      return 0; 
} 
