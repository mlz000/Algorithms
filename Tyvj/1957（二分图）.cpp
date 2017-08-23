#include<cstdio>   //二分图 最小覆盖路径 
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath> 
using namespace std;
const int N=2005;
bool d[N][N],v[N];
int l[N]; 
int n,m;
bool can(int x)
{
   int j;
   for(j=1;j<=n;++j)
   {
      if(d[x][j] && !v[j])
      {
        v[j]=true;
        if(!l[j] || can(l[j]))
        {
           l[j]=x;
           return true;
        }
      }
   }
   return false;
}
int main()
{
     int i,j,k,x,y;
     scanf("%d%d",&n,&m);
     for(i=1;i<=m;++i)
     {
        scanf("%d%d",&x,&y);
        d[x][y]=true; 
     } 
     for(i=1;i<=n;++i)
      for(j=1;j<=n;++j)
       for(k=1;k<=n;++k)
          d[i][j]=d[i][j]|(d[i][k]&d[k][j]); //传递闭包 
     int ans=0;
     for(i=1;i<=n;++i)
     {
       memset(v,false,sizeof(v));
       if(can(i)) ans++;
     }
     printf("%d",n-ans);  
     return 0;
}
