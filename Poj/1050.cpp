#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int N=105;
int a[N][N],sum[N][N];
int main()
{
    int i,j,k,p,ans,n;
    scanf("%d",&n);
    for(i=1;i<=n;++i)
     for(j=1;j<=n;++j)
      {
            scanf("%d",&a[i][j]);
            sum[i][j]=sum[i][j-1]+a[i][j];
      }
      int MAX=-1;
      for(i=1;i<=n;++i)
      {
         for(j=i;j<=n;++j)
         {  
             p=sum[1][j]-sum[1][i-1];
             ans=p;
             for(k=2;k<=n;++k)
             {
               if(ans>0) ans+=sum[k][j]-sum[k][i-1];
               else ans=sum[k][j]-sum[k][i-1];
               if(ans>p) p=ans;
             } 
              if(p>MAX) MAX=p;
         }
      }
     printf("%d\n",MAX);
    // system("pause");
     return 0;
} 
