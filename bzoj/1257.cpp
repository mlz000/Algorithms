#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath> 
using namespace std;
typedef long long ll;
int main()
{
      int n,k;
      scanf("%d%d",&n,&k); 
      ll ans=0ll; 
      for(int i=1;i<=n;i++) 
      { 
            int a=k/i,l=k/(a+1)+1,r=a?k/a:n; 
            if(r>=n)r=n; 
            ans+=ll(k)*(r-l+1)-ll(a)*(l+r)*(r-l+1)/2; 
            i=r; 
      } 
      printf("%lld",ans); 
      return 0; 
} 
