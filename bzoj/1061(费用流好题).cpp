//https://www.byvoid.com/blog/noi-2008-employee/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <climits>
#include <cstring>
using namespace std;
const int N=1005,M=10005,INF=1000000000;
int S,T,n,m,tot,ask[N],head[N],d[N],p[N];
bool v[N];
long long ans;
struct data
{
      int u,v,next,f,w;
}edge[M*4];
void add(int u,int v,int f,int w)
{
      edge[tot].u=u;
      edge[tot].v=v;
      edge[tot].f=f;
      edge[tot].w=w;
      edge[tot].next=head[u];
      head[u]=tot++;
      edge[tot].u=v;
      edge[tot].v=u;
      edge[tot].f=0;
      edge[tot].w=-w;
      edge[tot].next=head[v];
      head[v]=tot++;
}
bool spfa()
{
      int i,j;
      queue<int>q;
      for(i=0;i<=n+2;++i)     d[i]=INT_MAX;
      d[S]=0;
      p[S]=-1;
      q.push(S);
      while(q.size())
      {
            i=q.front();
            q.pop();
            v[i]=false;
            for(j=head[i];j!=-1;j=edge[j].next)
            {
                  if(edge[j].f>0 && d[i]+edge[j].w<d[edge[j].v])
                  {
                      d[edge[j].v]=d[i]+edge[j].w;
                      p[edge[j].v]=j;
                      if(!v[edge[j].v])
                      {
                        q.push(edge[j].v);
                        v[edge[j].v]=true;
                      }  
                  }
            }
      } 
      return (d[T]<INT_MAX);
}
void solve()
{
      int i,flow=INT_MAX;
      for(i=p[T];i!=-1;i=p[edge[i].u])    flow=min(flow,edge[i].f);
      for(i=p[T];i!=-1;i=p[edge[i].u])
      {
            edge[i].f-=flow;
            edge[i^1].f+=flow;
      }
      ans+=flow*d[T];
}
int main()
{
      scanf("%d%d",&n,&m);
      int i;      
      memset(head,-1,sizeof(head));
      for(i=1;i<=n;++i) scanf("%d",&ask[i]);
      for(i=1;i<=m;++i)
      {
            int a,b,d;
            scanf("%d%d%d",&a,&b,&d);
            add(a,b+1,INF,d);
      }
      S=0,T=n+2;
      for(i=1;i<=n+1;++i)
      {
            int tmp=ask[i]-ask[i-1];
            if(tmp>0)   add(S,i,tmp,0);
            else add(i,T,-tmp,0);
            if(i>1)     add(i,i-1,INF,0);
      }
      while(spfa()) 
      {
            solve();
      }
      printf("%lld",ans);
	return 0;
}
