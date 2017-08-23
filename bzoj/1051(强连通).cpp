#include<cstdio> 
#include<stack>
#include<algorithm>
#include<iostream>
using namespace std;
const int N=10005,M=50005;
int tot,cnt,to[M],head[N],next[M],dfn[N],low[N],fa[N],du[N];
bool ins[N];
stack<int>s;
void add(int u,int v)
{
    to[++tot]=v;
    next[tot]=head[u];
    head[u]=tot;
}
void tarjan(int u)
{
    dfn[u]=low[u]=++tot;
    s.push(u);
    ins[u]=true;
    for(int i=head[u];i;i=next[i])
    {
        if(!dfn[to[i]]) 
        {
            tarjan(to[i]);
            low[u]=min(low[u],low[to[i]]);
        }
        else if(ins[to[i]]) low[u]=min(low[u],dfn[to[i]]);
    }
    if(dfn[u]==low[u])
    {
        int v;
        cnt++;
        do
        {
           v=s.top();
           s.pop();
           ins[v]=false;
           fa[v]=cnt; 
        }while(u!=v);
    }
}
int main()
{
    int i,j,n,m;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;++i)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        add(a,b);
    }
    tot=0;
    for(i=1;i<=n;++i)
    if(!dfn[i]) tarjan(i); 
    int ans=0;
    for(i=1;i<=n;++i)
     for(j=head[i];j;j=next[j])
     if(fa[i]!=fa[to[j]])   ++du[fa[i]];
    for(i=1;i<=cnt;++i)
    {
       if(du[i]==0)
       {    
         if(ans)    {printf("0");return 0;}
         else
         {
            for(j=1;j<=n;++j)
             if(fa[j]==i)   ++ans;
         }   
       } 
    }
    printf("%d",ans);
    return 0;
}
