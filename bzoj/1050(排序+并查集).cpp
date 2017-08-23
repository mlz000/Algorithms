#include<cstdio>
#include<iostream>
#include<algorithm>
#include<stack>
#include<queue>
#include<cstring>
using namespace std;
const int N=505,M=5005;
int f[N];
bool v[N];
struct data
{
      int u,v,w;
}a[M];
bool cmp(const data p,const data q) {return p.w<q.w;}
int find(int x)
{
      if(f[x]==x) return f[x];
      else return f[x]=find(f[x]);
}
void Union(int u,int v)
{
     int fu=find(u);
     int fv=find(v); 
     if(fu!=fv)   f[fv]=fu;
}
int main()
{
      int i,j,n,m;
      scanf("%d%d",&n,&m);
      for(i=1;i<=m;++i)  scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
      sort(&a[1],&a[m+1],cmp);
      int s,t;
      scanf("%d%d",&s,&t);
      bool flag=false;
      int ansx=1,ansy=100000;
      for(i=1;i<=m;++i)
      {
           for(j=1;j<=n;++j)  f[j]=j;
           for(j=i;j<=m;++j) 
           {
              Union(a[j].u,a[j].v); 
              if(find(s)==find(t))  {flag=true;break;}   
           }
           if(j<=m)
           {
               if(ansx*a[j].w<a[i].w*ansy)
               {
                  ansy=a[j].w;
                  ansx=a[i].w;
               }   
           }
      }
      if(!flag)   printf("IMPOSSIBLE");
      else 
      {
            int tmp=__gcd(ansy,ansx);
            if(tmp==ansx)     printf("%d",ansy/tmp);
            else printf("%d/%d",ansy/tmp,ansx/tmp);
      }
      return 0;
}
