#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=1005;
int a[N],sum[N][N];
long long rps[N][N],rpb[N][N];
int main()
{
    int i,j,k,n,m;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i)
     {
        scanf("%d",&a[i]);
         sum[i][i]=a[i];
     }
      for(i=1;i<=n-1;++i)
      {
         rps[i][i+1]=a[i]+a[i+1];
         rpb[i][i+1]=a[i]+a[i+1];
      }
    for(i=1;i<=n;++i)
     for(j=i+1;j<=n;++j)
      sum[i][j]=sum[i][j-1]+a[j];
    for(i=n-1;i>=1;--i)
     for(j=i+1;j<=n;++j)
      {
        rps[i][j]=0xfffffff;
        for(k=i;k<=j-1;++k)
        {
			rps[i][j]=min(rps[i][j],rps[i][k]+rps[k+1][j]+sum[i][j]);
            rpb[i][j]=max(rpb[i][j],rpb[i][k]+rpb[k+1][j]+sum[i][j]);
		}
      }
      if(m>rpb[1][n]) printf("It is easy");
      else if(m<rps[1][n]) printf("I am..Sha...X");
      else printf("I will go to play WarIII");
      return 0;
}
