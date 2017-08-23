#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int N=15,INF=0x3f3f3f3f;
double tot,f[N][N][N][N][N],sum[N][N],g[N][N]; 
double dfs(int x1,int y1,int x2,int y2,int cs)
{
    int i,j;
    double &tmp=f[x1][y1][x2][y2][cs];
    if(tmp<INF)  return tmp;
    if(!cs)
    {
        tmp=sum[x2][y2]+sum[x1-1][y1-1]-sum[x1-1][y2]-sum[x2][y1-1]-tot;
        tmp=tmp*tmp;
        return tmp;
    }
    for(i=x1;i<x2;++i)
     for(j=0;j<cs;++j)
     tmp=min(tmp,dfs(x1,y1,i,y2,j)+dfs(i+1,y1,x2,y2,cs-j-1));
    for(i=y1;i<y2;++i)
     for(j=0;j<cs;++j)
     tmp=min(tmp,dfs(x1,y1,x2,i,j)+dfs(x1,i+1,x2,y2,cs-j-1));
    return tmp;  
}
int main()
{
    int a,b,n;
    scanf("%d%d%d",&a,&b,&n);
    tot=0.0;
    for(int i=1;i<=a;++i)
     for(int j=1;j<=b;++j)
     scanf("%lf",&g[i][j]),tot+=g[i][j];
    tot=tot/n;
    for(int i=1;i<=a;++i)
     for(int j=1;j<=b;++j)
     sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+g[i][j];
    for(int i=0;i<=10;++i)
     for(int j=0;j<=10;++j)
      for(int k=0;k<=10;++k)
       for(int l=0;l<=10;++l)
        for(int m=0;m<=10;++m)
         f[i][j][k][l][m]=INF;
    dfs(1,1,a,b,n-1);  
    printf("%.2lf",sqrt(f[1][1][a][b][n-1]/n));
    return 0;
} 
