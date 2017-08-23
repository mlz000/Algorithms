#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N=10005,M=1000005*2;
int tot,to[M],d[N],head[N],next[M]; 
bool vis[N];
void add(int u,int v)
{
    to[++tot]=v;
    next[tot]=head[u];
    head[u]=tot;
}
int main()
{
    int i,j,k,n,m;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;++i)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        add(a,b);
        add(b,a);
    }
    int ans=0;
    for(i=n;i>=1;--i)
    {
        for(k=0,j=1;j<=n;++j)
         if(!vis[j] && d[j]>=d[k]) k=j;
        vis[k]=true;
        for(j=head[k];j;j=next[j]) 
        if(!vis[to[j]]) ans=max(ans,++d[to[j]]);
    }
    printf("%d",ans+1);
    return 0;
}
