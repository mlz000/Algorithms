#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
#define cnt(i,j) ((i-1)*(m-1)+j)
using namespace std;
const int N=1005;
int s,t;
struct data
{
    int v;
    int l;
}edge[N*N*4];
bool operator< (const data p,const data q) {return p.l>q.l;}
priority_queue<data> q;
int tot,head[N*N*4],next[N*N*4],dis[N*N*4];
bool v[N*N*4];
void add(int u,int v,int w)
{
    edge[++tot].v=v;
    edge[tot].l=w;
    next[tot]=head[u];
    head[u]=tot;
}
void dij()
{
    memset(dis,127,sizeof(dis));
    dis[s]=0;
    data tmp;
    tmp.v=s;
    tmp.l=0;
    q.push(tmp);
    while(q.size())
    {
        tmp=q.top();
        q.pop();
        if(v[tmp.v]) continue;
        v[tmp.v]=true;
        for(int e=head[tmp.v];e;e=next[e])
        {
            if(dis[tmp.v]+edge[e].l<dis[edge[e].v])
            {
                dis[edge[e].v]=dis[tmp.v]+edge[e].l;
                data tmp2;
                tmp2.v=edge[e].v;
                tmp2.l=dis[edge[e].v];
                q.push(tmp2);
            }   
        }   
    }
}
int main()
{
    int i,j,n,m;
    scanf("%d%d",&n,&m);
    t=(n-1)*(m-1)*2+1;
    int x;
    if(n==1 || m==1) 
    {
        int ans=1000000000;
        if(n==1)   for(i=1;i<=m-1;++i) scanf("%d",&x),ans=min(ans,x);
        else if(m==1) for(i=1;i<=n-1;++i) scanf("%d",&x),ans=min(ans,x); 
        if(n==1 && m==1) ans=0;
        printf("%d",ans);
        return 0;
    }
    for(i=1;i<=n;++i)
     for(j=1;j<m;++j)
     {
        scanf("%d",&x);
        if(i==1) add(cnt(i,j)*2,t,x);
        else if(i==n) add(s,cnt(i-1,j)*2-1,x);
        else add(cnt(i,j)*2,cnt(i-1,j)*2-1,x);
     }
    for(i=1;i<=n-1;++i)
     for(j=1;j<=m;++j)
     {
        scanf("%d",&x);
        if(j==1) add(s,cnt(i,j)*2-1,x);
        else if(j==m) add(cnt(i,j-1)*2,t,x);
        else add(cnt(i,j-1)*2,cnt(i,j)*2-1,x);
     } 
    for(i=1;i<=n-1;++i)
     for(j=1;j<=m-1;++j)
     {
        scanf("%d",&x);
        add(cnt(i,j)*2-1,cnt(i,j)*2,x);
     } 
    dij();
    printf("%d",dis[t]);
    return 0;
}
