#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
const int N=100000;
int n,m,f[N];
struct data {int u,v,w;}e[N];
bool cmp(const data p,const data q) {return p.w<q.w;}
int find(int x)
{
      if(f[x]==x) return f[x];
      else return f[x]=find(f[x]);
}
bool check(int w)
{
      for(int i=1;i<=n;++i)   f[i]=i;
      for(int i=1;i<=m;++i)
      if(e[i].w<=w)
      {
            int p=find(e[i].u);
            int q=find(e[i].v);
            if(p!=q)    f[p]=q;
      }
      for(int i=1;i<=n;++i)
      if(find(i)!=find(1))   return false;
      return true;
}
int main()
{
     int i;
     scanf("%d%d",&n,&m);
     for(i=1;i<=m;++i)  scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
     sort(&e[1],&e[m+1],cmp);
     int l=1,r=m;
     while(l<=r)
     {
          if(l==r)      break;
          int mid=(l+r)>>1;
          if(check(e[mid].w))   r=mid;
          else l=mid+1;     
     }
     printf("%d %d",n-1,e[l].w);
     return 0;
}
