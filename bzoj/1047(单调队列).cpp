#include<cstdio>//单调队列 
#include<algorithm>
#include<iostream>
#include<cmath>
#include<climits> 
using namespace std;
const int N=1010;
int x[N][N],a[N][N],b[N][N],p[N],q[N];
int main()
{
    int n,m,k,i,j;
    scanf("%d%d%d",&n,&m,&k);
    for(i=1;i<=n;++i)
    {
      int l=1,r=0,f=1,t=0;
      for(j=1;j<=m;++j)
      {   
         scanf("%d",&x[i][j]);
         while(l<=r && p[l]+k<=j) ++l;
         while(l<=r && x[i][j]>x[i][p[r]])  --r;
         p[++r]=j;
         a[i][j]=x[i][p[l]];
         while(f<=t && q[f]+k<=j)   ++f;
         while(f<=t && x[i][j]<x[i][q[t]])  --t;
         q[++t]=j;
         b[i][j]=x[i][q[f]];
      }
    }     
    int ans=INT_MAX;
    for(j=k;j<=m;++j)
    {
        int l=1,r=0,f=1,t=0;
        for(i=1;i<k;++i)
        {
            while(l<=r && a[i][j]>a[p[r]][j])   --r;
            p[++r]=i;
            while(f<=t && b[i][j]<b[q[t]][j])   --t;
            q[++t]=i;
        }
        for(i=k;i<=n;++i)
        {
            while(l<=r && p[l]+k<=i)    ++l;
            while(l<=r && a[i][j]>a[p[r]][j])   --r;
            p[++r]=i; 
            while(f<=t && q[f]+k<=i)    ++f;
            while(f<=t && b[i][j]<b[q[t]][j])   --t;
            q[++t]=i;
            ans=min(ans,a[p[l]][j]-b[q[f]][j]);
        }
    }
    printf("%d",ans);
    return 0;
}
