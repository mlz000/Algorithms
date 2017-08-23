#include<cstdio>
#include<vector>
#include<string>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
const int INF = 2000000000;
typedef struct{int v,next,val;}edge;
const int Max_Vertex=20010;
const int Max_Edge=50000;
edge e[Max_Edge];
int head[Max_Vertex],eid;
int n,m;
int h[Max_Vertex];
int gap[Max_Vertex];
int source,sink;
inline void init()
{
 memset(head,-1,sizeof(head));
 eid=0;  
}
inline void add_edge(int u,int v,int val)
{
 e[eid].v=v;
 e[eid].val=val;
 e[eid].next=head[u];
 head[u]=eid++;
 e[eid].v=u;
 e[eid].val=0;
 e[eid].next=head[v];
 head[v]=eid++;
}
int dfs(int pos,int cost)
{
 if(pos==sink)
 {
  return cost;
 }
 int j,minh=n-1,lv=cost,d;
 for(j=head[pos];j!=-1;j=e[j].next)
 {
  int v=e[j].v,val=e[j].val;
  if(val>0) 
  {
   if (h[v]+1==h[pos])
   { 
    d=min(lv,e[j].val);
    d=dfs(v,d);
    e[j].val-=d;
    e[j^1].val+=d;
    lv-=d;
    if (h[source]>=n) return cost-lv;   
    if (lv==0) break;
   }
   if (h[v]<minh) minh=h[v];
  }
 }
 if (lv==cost) 
 {
  --gap[h[pos]];
  if (gap[h[pos]]==0) h[source]=n;
  h[pos]=minh+1;
  ++gap[h[pos]];
 }
 return cost-lv;
}
int ISAP(int src,int des)
{
 source=src;
 sink=des;
 int ret=0;
 memset(gap,0,sizeof(gap));
 memset(h,0,sizeof(h));
 gap[src]=n; 
 while(h[src]<n)
 {
  ret+=dfs(src,INF);
 }
 return ret; 
}
int  main()
{
 int np,nc,npp,s,e,cost,nn;
 while(scanf("%d%d%d%d",&nn,&np,&nc,&m)==4)
 {
  n=nn+2;
  getchar();
  init();
  while(m--)
  {
   scanf(" (%d,%d)%d",&s,&e,&cost);
   //getchar();
   add_edge(s+1,e+1,cost);//使得各结点标号从1开始，
   //以便方便构建一个0源点和n+1汇点
  }
  while(np--)//构建一个源点到各发电站路
  {
   scanf(" (%d)%d",&npp,&cost);
   //getchar();
   add_edge(0,npp+1,cost);
  }
  while(nc--)//构建各发用户到汇点路
  {
   scanf(" (%d)%d",&npp,&cost);
   //getchar();
   add_edge(npp+1,n-1,cost);
  }
  printf("%d\n",ISAP(0,n-1));
 }
 return 0;
}
