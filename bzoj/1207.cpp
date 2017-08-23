#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int N=10005;
int f[N],t[N],x[N],y[N];
int main()
{
      int n,m,i,j;
      scanf("%d%d",&n,&m);
      for(i=1;i<=m;++i) scanf("%d%d%d",&t[i],&x[i],&y[i]);
      int ans=0;
      for(i=1;i<=m;++i)
      { 
       for(j=1;j<i;++j)
       {
            if(abs(x[i]-x[j])+abs(y[i]-y[j])<=t[i]-t[j])    f[i]=max(f[i],f[j]+1);
       }
       f[i]=max(f[i],1);
       ans=max(ans,f[i]);     
      }
      printf("%d",ans);
	return 0;
}
