#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=100005,M=2000005;
int tot,to[M],we[M],next[M],head[N],d[N],ans1,ans2,MAX,MIN;
bool v[N],vis[M];
inline int ABS(int x)   {return x>0?x:-x;}
void add(int u,int v,int w)
{
     to[++tot]=v;
     we[tot]=w;
     next[tot]=head[u];
     head[u]=tot;       
}
void dfs(int u)
{
    v[u]=true;
    for(int i=head[u];i;i=next[i])
    {
      if(v[to[i]])  ans2=__gcd(ans2,ABS(d[u]+we[i]-d[to[i]]));
      else d[to[i]]=d[u]+we[i],dfs(to[i]);
    }
}
void tree(int u)
{
    v[u]=true;
    MAX=max(MAX,d[u]);
    MIN=min(MIN,d[u]);
    for(int i=head[u];i;i=next[i])
    {
        if(!vis[i])
        {
            vis[i]=vis[i^1]=true;
            d[to[i]]=d[u]+we[i];
            tree(to[i]);
        }
    }
}
int main()
{
    int i,n,m,x,y;
    scanf("%d%d",&n,&m);
    tot=1;
    for(i=1;i<=m;++i)
    {
        scanf("%d%d",&x,&y);
        add(x,y,1);
        add(y,x,-1);   
    } 
    for(i=1;i<=n;++i)   if(!v[i])   dfs(i); 
    if(ans2) for(ans1=3;ans1<=ans2 && ans2%ans1;++ans1);
    else 
    {
        memset(v,false,sizeof(v));
        for(i=1;i<=n;++i)
        if(!v[i]) 
        {
            MAX=MIN=d[i]=0;
            tree(i);
            ans2+=MAX-MIN+1;
        }
        ans1=3;
    }
    if(ans2<3)  ans1=ans2=-1;
    printf("%d %d",ans2,ans1);
    return 0;
} 
