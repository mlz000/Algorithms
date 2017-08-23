#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=100005;
long long ans,a[N];
int main()
{
      int i,j,n,m;
      scanf("%d%d",&n,&m);
      int x=min(n,m);
      for(i=1;i<=x;++i) a[i]=(long long)(n/i)*(m/i);
      for(i=x;i>=1;--i) 
       for(j=2;j*i<=x;++j)
       a[i]-=a[j*i]; 
      for(i=1;i<=x;++i) ans+=(2*i-1)*a[i];
      printf("%lld",ans);
      return 0;
}
