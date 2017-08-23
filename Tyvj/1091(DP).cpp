#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=1005,MOD=9901;
int a[N],f[N][N*2]; //以I为尾项公差为a[i]-a[j]+1000 
int main()
{
    int i,j,n;
    scanf("%d",&n);
     for(i=1;i<=n;++i)
      scanf("%d",&a[i]);
     int ans=n;//每个单独的等差数列 
     for(i=1;i<=n;++i)
    {
      for(j=1;j<=i-1;++j)
     {
       f[i][a[i]-a[j]+1000]+=f[j][a[i]-a[j]+1000]+1;
       ans=(ans+f[j][a[i]-a[j]+1000]+1)%MOD; 
     }
    }
      printf("%d",ans);
      //system("pause");
      return 0;
}
