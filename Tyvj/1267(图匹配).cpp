#include<cstdio> 
#include<iostream>
#include<cstring> 
#include<algorithm> 
using namespace std;
const int N=1005;
int l[N];  
bool g[N][N],v[N]; 
int r,a,t; 
struct data
{
   double x;
   double y;
   double v; 
}b[N],s[N]; 
bool can(int u)
{
   int j; 
   for(j=1;j<=a;++j)
   {
     if(g[u][j] && !v[j]) 
     {
       v[j]=true; 
       if(!l[j] || can(l[j])) 
       {
         l[j]=u; 
         return true; 
       } 
     } 
   } 
   return false; 
} 
int main()
{ 
      int i,j;
      scanf("%d%d%d",&r,&a,&t);
      for(i=1;i<=a;++i)
       scanf("%lf%lf",&s[i].x,&s[i].y);
      for(i=1;i<=r;++i)
        scanf("%lf%lf%lf",&b[i].x,&b[i].y,&b[i].v);
      for(i=1;i<=r;++i)
       for(j=1;j<=a;++j)
       {
         if((b[i].x-s[j].x)*(b[i].x-s[j].x)+(b[i].y-s[j].y)*(b[i].y-s[j].y)<=b[i].v*b[i].v*t*t)
         g[i][j]=true; 
       }   
      int ans=0; 
      for(i=1;i<=r;++i)
      {
        memset(v,false,sizeof(v));
        if(can(i)) ans++; 
      } 
      printf("%d",ans); 
  //    system("pause");  
      return 0; 
} 

