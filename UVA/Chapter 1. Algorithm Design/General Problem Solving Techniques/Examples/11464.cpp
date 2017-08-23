#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=17,MAX=1000000;
int a[N][N],b[N][N];
int n;
int count(int x)
{
     int tmp=0;
     memset(b,0,sizeof(b));
     int i,j;
     for(i=0;i<n;++i)
     {
          if((x>>i)&1) b[1][i+1]=1;
          else if(a[1][i+1]==1) return MAX;
     }
     for(i=2;i<=n;++i)
      for(j=1;j<=n;++j)
       b[i][j]=a[i][j];
     for(i=1;i<n;++i)
      for(j=1;j<=n;++j)
      {
         int sum=0;
         if(i>1) sum+=b[i-1][j];
         if(i<n) sum+=b[i+1][j];
         if(j>1) sum+=b[i][j-1];
         if(j<n) sum+=b[i][j+1];
         if(sum%2!=0) 
         {
            if(b[i+1][j]==1) return MAX; 
            else b[i+1][j]=1;
         }
      } 
      for(i=1;i<=n;++i)
       for(j=1;j<=n;++j)
        tmp+=a[i][j]^b[i][j];
      return tmp;     
}
int main()
{
      int i,j,k,T;
      scanf("%d",&T);
      for(i=1;i<=T;++i)
      {
        scanf("%d",&n);
        for(j=1;j<=n;++j)
         for(k=1;k<=n;++k)
          scanf("%d",&a[j][k]);
        int ans=MAX;  
        for(j=0;j<(1<<n);++j)
         ans=min(ans,count(j));
        printf("Case %d: ",i); 
        if(ans==MAX) printf("-1\n");
        else printf("%d\n",ans); 
      }
      //system("pause"); 
      return 0;
}
