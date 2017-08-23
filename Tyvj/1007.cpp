#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
struct data
{
    int sz;
    int xb;
}k[1001],l[1001];
bool cmp1(const data &p,const data &q)
{
   return p.sz>q.sz;
}
bool cmp2(const data &p,const data &q)
{
   return p.xb<q.xb;
}
int main()
{
    int a,b,c,d,i,M,N,K,L,D;
    scanf("%d%d%d%d%d",&M,&N,&K,&L,&D);
    for(i=1;i<=M;++i)
    k[i].xb=i;
    for(i=1;i<=N;++i)
    l[i].xb=i;
    for(i=1;i<=D;++i)
      {
              scanf("%d%d%d%d",&a,&b,&c,&d);
             if(a<c) k[a].sz++;
             if(a>c) k[c].sz++;
             if(b<d) l[b].sz++;
             if(b>d) l[d].sz++;
      }
      sort(&k[1],&k[1001],cmp1);
      sort(&l[1],&l[1001],cmp1);
      sort(&k[1],&k[K+1],cmp2);
      sort(&l[1],&l[L+1],cmp2);
      for(i=1;i<=K;++i)
      printf("%d ",k[i].xb);
      printf("\n");
      for(i=1;i<=L;++i)
      printf("%d ",l[i].xb);
      //system("pasue");
      return 0;
}
