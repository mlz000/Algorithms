#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#define mid ((l+r)>>1)
using namespace std;
int n,tot;
int root[200010],lazy[8000010],sum[8000010],le[8000010],ri[8000010];
void add(int &X,int l,int r,int x,int y)
{
      if(x>r || y<l)    return;
      if(!X)     X=++tot;
      if(x<=l && y>=r)
      {
            lazy[X]++;
            sum[X]+=r-l+1;
            return ;
      }
      if(l<=mid)  add(le[X],l,mid,x,y);
      if(r>mid)   add(ri[X],mid+1,r,x,y);
      sum[X]=lazy[X]*(r-l+1)+sum[le[X]]+sum[ri[X]];
}
void update(int x,int y,int p)
{
      int l=1,r=n,k=1;
      while(l!=r)
      {
          add(root[k],1,n,x,y);
          if(p<=mid)   k=(k<<1),r=mid;
          else k=(k<<1)+1,l=mid+1;  
      }
      add(root[k],1,n,x,y);
}
int cnt(int k,int l,int r,int x,int y)
{
      if(!k || x>r || y<l)      return 0;
      if(x<=l && y>=r)  return sum[k];
      return cnt(le[k],l,mid,x,y)+cnt(ri[k],mid+1,r,x,y)+((y>r?r:y)-(x<l?l:x)+1)*lazy[k];
}
int ask(int x,int y,int p)
{
      int l=1,r=n,k=1,tmp;
      while(l!=r)
      {
            tmp=cnt(root[k<<1],1,n,x,y);
            if(tmp>=p)  k=(k<<1),r=mid;
            else p-=tmp,k=(k<<1)+1,l=mid+1; 
      }
      return l;
}
int main()
{
      int m,i,x,a,b,c;
      scanf("%d%d",&n,&m);
      for(i=1;i<=m;++i)
      {
            scanf("%d%d%d%d",&x,&a,&b,&c);
            if(x==1)    c=n-c+1,update(a,b,c);
            else printf("%d\n",n-ask(a,b,c)+1);
      } 
      return 0;
}
