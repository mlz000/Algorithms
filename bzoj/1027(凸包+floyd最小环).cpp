#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
const int N=505,INF=0x3f3f3f3f;
const double eps=1e-8;
int n,m,d[N][N];
struct data {double x,y;}a[N],b[N];
double Cross(data a,data b,data c)   {return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);}
double dot(data a,data b,data c)    {return (b.x-a.x)*(c.x-a.x)+(b.y-a.y)*(c.y-a.y);}
bool on(int p)
{
      for(int i=1;i<=n;++i)
      if(b[i].x!=a[p].x || b[i].y!=a[p].y) return false;
      return true;
}
bool check(int p,int q)
{
      for(int i=1;i<=n;++i)
      if(Cross(a[p],a[q],b[i])<=-eps)     return false;
      return true; 
}
bool judge()
{
      for(int i=3;i<=n;++i)
      if(abs(Cross(b[1],b[2],b[i]))>eps)  return false;
      for(int i=1;i<=m;i++)
        for(int j=i+1;j<=m;j++)
        {
            int cnt=0;
            for(int k=1;k<=n;k++)
                if(dot(b[k],a[i],a[j])<=eps) cnt++;
            if(cnt==n) return false;
        }
    return true;
}
int main()
{
      int i,j,k;
      scanf("%d%d",&m,&n);
      for(i=1;i<=m;++i) scanf("%lf%lf%lf",&a[i].x,&a[i].x,&a[i].y);
      for(i=1;i<=n;++i) scanf("%lf%lf%lf",&b[i].x,&b[i].x,&b[i].y);
      for(i=1;i<=m;++i)
      if(on(i))   {printf("1");return 0;} 
      if(judge()) {printf("-1");return 0;}
      int ans=INF;
      memset(d,0x3f,sizeof(d));
      for(i=1;i<=m;++i)
       for(j=1;j<=m;++j)
       if(i!=j)  if(check(i,j))     d[i][j]=1;   
      for(k=1;k<=m;++k)
       for(i=1;i<=m;++i)
        if(d[i][k]<INF)
         for(j=1;j<=m;++j)
         d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
      for(i=1;i<=m;++i) ans=min(ans,d[i][i]);
      if(ans==INF)      ans=-1;
      printf("%d",ans);   
      return 0;
}
