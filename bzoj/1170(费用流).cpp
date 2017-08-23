#include<cstdio>
#include<algorithm>
#include<iostream>
#include<queue>
#include<climits>
#include<cstring>
using namespace std;
const int N=1005;
int S,T,tot,head[N*N],t[N][N],p[N*N],d[N*N];
long long ans;
bool v[N*N];
struct data{int u,v,f,w,next;}e[N*N];
void add(int u,int v,int f,int w)
{
    e[tot].u=u,e[tot].v=v,e[tot].f=f,e[tot].w=w,e[tot].next=head[u];
    head[u]=tot++;
    e[tot].u=v,e[tot].v=u,e[tot].f=0,e[tot].w=-w,e[tot].next=head[v];
    head[v]=tot++; 
}
bool spfa()
{
    queue<int> q;
    for(int i=S;i<=T;++i)   d[i]=INT_MAX;
    d[S]=0;p[S]=-1;
    q.push(S);
    while(q.size())
    {
        int i=q.front();
        q.pop();
        v[i]=false;
        for(int j=head[i];j!=-1;j=e[j].next)
        {
            if(e[j].f>0 && d[i]+e[j].w<d[e[j].v])
            {
                d[e[j].v]=d[i]+e[j].w;
                p[e[j].v]=j;
                if(!v[e[j].v])
                {
                    q.push(e[j].v);
                    v[e[j].v]=true;
                }
            }
        }
    }
    return (d[T]<INT_MAX);
}
void cnt()
{
    int flow=INT_MAX;
    for(int i=p[T];i!=-1;i=p[e[i].u])   flow=min(flow,e[i].f);
    for(int i=p[T];i!=-1;i=p[e[i].u])
    {
        e[i].f-=flow;
        e[i^1].f+=flow;
    }
    ans+=flow*d[T];
}
int main()
{
    int m,n,i,j,k;
    scanf("%d%d",&m,&n);
    memset(head,-1,sizeof(head));
    for(i=1;i<=n;++i)
     for(j=1;j<=m;++j)  
      scanf("%d",&t[i][j]);
    S=0,T=n+n*m+1;
    for(i=1;i<=n;++i)   add(S,i,1,0);
    for(i=n+1;i<=n+n*m;++i) add(i,T,1,0);
    for(i=1;i<=n;++i)
     for(j=1;j<=m;++j)
      for(k=1;k<=n;++k)
      add(i,j*n+k,1,(n-k+1)*t[i][j]);
    while(spfa()) cnt();
    printf("%.2lf",(double)ans/n);   
    return 0;
}
