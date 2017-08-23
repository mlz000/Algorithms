#include<iostream>//
#include<cstdio>
#include<climits>
#include<cstring>
#include<queue>
using namespace std;
struct edge
{
    int u,v,next,f,w;
}e[40010];
int n,m;
int mincost=0;
int p[2000],d[2000];
int num=0;
int first[2000];
int s,t,x;
void add(int s,int t,int w,int c)
{
    e[num].f=c;
    e[num].next=first[s];
    first[s]=num;
    e[num].u=s;
    e[num].v=t;
    e[num++].w=w;
    return ;
}
void addedge(int s,int t,int w,int c)
{
    add(s,t,w,c);
    add(t,s,-w,0);
    return ;
}
bool spfa()
{
    int i,j;
    queue<int> q;
    bool ok[2000];
    memset(ok,false,sizeof(ok));
    for(i=0;i<=n+1;i++)
    {
        d[i]=INT_MAX;
    }
    d[s]=0;
    ok[s]=true;
    p[s]=-1;
    q.push(s);
    while(!q.empty())
    {
        i=q.front();
        q.pop();
        ok[i]=false;
        for(j=first[i];j!=-1;j=e[j].next)
        {
            if(e[j].f>0&&d[i]+e[j].w<d[e[j].v])
            {
                d[e[j].v]=d[i]+e[j].w;
                p[e[j].v]=j;
                if(!ok[e[j].v])
                {
                    q.push(e[j].v);
                    ok[e[j].v]=true;
                }
            }
        }
    }
    if(d[t]<INT_MAX)
       return 1;
    else return 0;
}
void solve()
{
    int i;
    int minflow=INT_MAX;
    for(i=p[t];i!=-1;i=p[e[i].u])
    {
        if(minflow>e[i].f)
            minflow=e[i].f;
    }
    for(i=p[t];i!=-1;i=p[e[i].u])
    {
        e[i].f-=minflow;
        e[i^1].f+=minflow;
    }
        mincost+=d[t]*minflow;
}
int main()
{
    scanf("%d%d",&n,&m);
    int i;
    int a,b,c;
    memset(first,-1,sizeof(first));
    for(i=1;i<=m;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        addedge(a,b,c,1);
        addedge(b,a,c,1);
    }
    s=0;
    t=n+1;
    addedge(s,1,0,2);
    addedge(n,t,0,2);
    while(spfa())
    {
        solve();
    }
    printf("%d\n",mincost);
    return 0;
}

