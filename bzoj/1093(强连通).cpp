#include<cstdio>
#include<iostream>
#include<algorithm>
#include<stack>
#include<queue>
#include<cstring>
using namespace std;
const int N=100005,M=1000005;
int tot,inde,cnt,n,m,x,a[M],b[M],to[M],dfn[N],low[N],head[N],next[M],fa[N],f[N],sum[N],in[N],num[N],vis[N];
bool ins[N];
void add(int u,int v)
{
      to[++tot]=v;
      next[tot]=head[u];
      head[u]=tot;
}
stack<int> S;
void tarjan(int u)
{
      dfn[u]=low[u]=++inde;
      S.push(u);
      ins[u]=true;
      for(int i=head[u];i;i=next[i])
      {
            int v=to[i];
            if(!dfn[v])
            {
                  tarjan(v);
                  low[u]=min(low[u],low[v]);
            }
            else if(ins[v])   low[u]=min(low[u],dfn[v]);
      }
      if(dfn[u]==low[u])
      {
            int v;
            ++cnt;
            do
            {
                 v=S.top();
                 S.pop();
                 ins[v]=false;
                 fa[v]=cnt;
                 sum[cnt]++;
            }while(u!=v);
      }
}
void solve()
{
      queue<int> q;
      for(int i=1;i<=cnt;++i)
      if(in[i]==0) 
      {
            q.push(i);
            f[i]=sum[i];
            num[i]=1;
      }
      while(q.size())
      {
            int u=q.front();
            q.pop();
            for(int i=head[u];i;i=next[i])
            {
                  int v=to[i];
                  --in[v];
                  if(!in[v])  q.push(v);
                  if(vis[v]==u)     continue;//ÖØ±ß
                  if(f[v]<f[u]+sum[v])
                  {
                        f[v]=f[u]+sum[v];
                        num[v]=num[u];
                  } 
                  else if(f[v]==f[u]+sum[v])    num[v]=(num[v]+num[u])%x;
                  vis[v]=u;
            }
      }
}
int main()
{
      scanf("%d%d%d",&n,&m,&x);
      for(int i=1;i<=m;++i)
      {
          scanf("%d%d",&a[i],&b[i]);
          add(a[i],b[i]); 
      }
      for(int i=1;i<=n;++i)
      if(!dfn[i]) tarjan(i);
      memset(head,0,sizeof(head));tot=0; 
      for(int i=1;i<=m;++i)
      if(fa[a[i]]!=fa[b[i]])  add(fa[a[i]],fa[b[i]]),in[fa[b[i]]]++;
      solve();
      int MAX=0,ans=0; 
      for(int i=1;i<=cnt;++i)     
      {
            if(f[i]>MAX)     MAX=f[i],ans=num[i];
            else if(f[i]==MAX)     ans=(ans+num[i])%x; 
      }
      printf("%d\n%d",MAX,ans); 
      return 0;
}
