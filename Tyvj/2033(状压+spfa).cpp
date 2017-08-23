#include<iostream>//真相是答案最多2位。。。。。哭瞎了 
#include<cstdio>
#include<queue> 
#include<cstring>
#include<climits> 
#include<algorithm>
using namespace std;
const int N=20,M=1010,P=1<<19;
long long f[P][N]; 
int v[P],head[N]; 
int n,tot; 
bool vis[P][N]; 
struct data
{
   int v;
   int t; 
   int next; 
}edge[M*2]; 
struct data2{int pos;int x;}; 
void add(int u,int v,int t)
{
  edge[++tot].v=v;
  edge[tot].t=t;
  edge[tot].next=head[u];
  head[u]=tot; 
} 
void dfs(int x)//记忆化搜索 
{
  if(v[x]) return; 
  v[x]=1;
  for(int i=0;i<n;++i)
  {
    if(!(x>>i&1))//第i+1个位置没到 
    {
     dfs(x|1<<i);
     f[x][0]=min(f[x][0],f[x|1<<i][0]); 
    } 
  } 
} 
void spfa()
{
  queue<data2> q; 
  memset(f,0x3f,sizeof(f));
  data2 tmp;
  tmp.pos=1;tmp.x=1;
  q.push(tmp); 
  f[1][1]=0;//装压
  int l; 
  while(q.size())
  {
    int i=q.front().pos;int j=q.front().x;q.pop();
    vis[i][j]=false;  
    for(int e=head[j];e;e=edge[e].next)
    {
      if(f[l=i|1<<edge[e].v-1][edge[e].v]>f[i][j]+edge[e].t)
      {
        f[l][edge[e].v]=f[i][j]+edge[e].t;
        if(!vis[l][edge[e].v])
        {
         vis[l][edge[e].v]=true; 
         tmp.pos=l;
         tmp.x=edge[e].v;
         q.push(tmp); 
        } 
      } 
    } 
  } 
} 
int main()
{ 
    int i,j,m; 
    int x,y,t; 
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;++i)
    {
      scanf("%d%d%d",&x,&y,&t);
      add(x,y,t);
      add(y,x,t); 
    } 
    spfa(); 
    for(i=1;i<1<<n;++i)
     for(j=1;j<=n;++j) 
     f[i][0]=min(f[i][0],f[i][j]);
    dfs(0);
    long long ans=INT_MAX;  
   for(i=1;i<1<<n;i++)
    if(ans>max(f[i][0],f[(1<<n)-1-i][0]))
     ans=max(f[i][0],f[(1<<n)-1-i][0]);
    printf("%I64d",ans); 
    //system("pause"); 
    return 0;
}

