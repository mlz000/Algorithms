#include<iostream>//状压DP 
#include<stack> 
#include<cstdio> 
#include<cstring> 
#include<climits> 
#include<algorithm>
using namespace std; 
const int N=1030;
int a[N],sum[N]; 
long long f[N][1030]; 
int main()
{
     int n,k,l,r;
     int i,j; 
     long long he=0ll; 
     scanf("%d%d%d%d",&n,&k,&l,&r);
     memset(f,-0x3f,sizeof(f)); 
     for(i=1;i<=n;++i)
      {
        scanf("%d",&a[i]); 
        he+=a[i]; 
      } 
     for(i=0;i<=(1<<k)-1;++i)
     {
       f[0][i]=0;
       int tot=0;
       int x=i;
       while(x>0)
       {
         tot=tot+(x&1);
         x=x>>1; 
       } 
       sum[i]=tot;//每种状态取了多少葡萄 
     } 
     for(i=1;i<=n;++i)
      for(j=0;j<=(1<<k)-1;++j)
       if(sum[j]>=l && sum[j]<=r) 
       {
         f[i][j]=max(f[i][j],max(f[i-1][j>>1],f[i-1][(j>>1)+(1<<(k-1))])+(j&1)*a[i]); 
       }
     long long ans=-0x3f3f3f3f;
     for(i=0;i<=(1<<k);++i)
      if(sum[i]>=l && sum[i]<=r)
       if(f[n][i]>ans) ans=f[n][i]; 
     cout<<ans*2-he;    
     //system("pause"); 
     return 0;
}

