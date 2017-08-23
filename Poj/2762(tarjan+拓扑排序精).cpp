#include<iostream>
#include<stack> 
#include<cstdio> 
#include<cstring> 
#include<climits> 
#include<algorithm>
using namespace std; 
const int N=1005,M=6005; 
int n,m,index,tot,cnt,head[N],head2[N],dfn[N],low[N],fa[N],in[N];
bool flag,v[N]; 
stack<int>S; 
struct data
{
  int v;
  int next; 
}edge[M*2],edge2[M*2]; 
void add(int u,int v)
{
   edge[++tot].v=v;
   edge[tot].next=head[u]; 
   head[u]=tot; 
} 
void readd(int u,int v)
{
   edge2[++tot].v=v;
   edge2[tot].next=head2[u]; 
   head2[u]=tot; 
} 
void init()
{
   scanf("%d%d",&n,&m); 
   index=0;cnt=0;tot=0;flag=false; 
   while(S.size())  S.pop(); 
   memset(head,-1,sizeof(head)); 
   memset(head2,-1,sizeof(head2)); 
   memset(fa,0,sizeof(fa)); 
   memset(in,0,sizeof(in)); 
   memset(dfn,0,sizeof(dfn));
   memset(low,0,sizeof(low));
   memset(v,false,sizeof(v)); 
   int i,a,b; 
   for(i=1;i<=m;++i)
   {
     scanf("%d%d",&a,&b);
     add(a,b); 
   } 
} 
void tarjan(int u)
{
    dfn[u]=low[u]=++index;
    S.push(u); 
    v[u]=true; 
    for(int e=head[u];e!=-1;e=edge[e].next)
    {
       if(!dfn[edge[e].v])
       {
         tarjan(edge[e].v);
         low[u]=min(low[u],low[edge[e].v]); 
       } 
       else if(v[edge[e].v]) low[u]=min(low[u],dfn[edge[e].v]); 
    } 
    if(dfn[u]==low[u])
    {
      ++cnt;
      int t; 
      do
      {
       t=S.top();
       v[t]=false; 
       S.pop(); 
       fa[t]=cnt; 
      }while(u!=t);  
    } 
} 
void rebuild()
{
   tot=0; 
   int i,e; 
   for(i=1;i<=n;++i)
   {
     for(e=head[i];e!=-1;e=edge[e].next)
     {
       if(fa[i]!=fa[edge[e].v])
       {
         readd(fa[i],fa[edge[e].v]);
         in[fa[edge[e].v]]++; 
       } 
     } 
   } 
} 
void tuopu()
{
    int i,e,sum=0; 
    while(S.size()) S.pop(); 
    for(i=1;i<=cnt;++i)
    {
      if(in[i]==0) sum++;
      if(sum>=2)  {flag=false;return;} 
      S.push(i); 
    } 
    for(i=1;i<=cnt;++i)
    {
      sum=0; 
      int x=S.top();
      S.pop(); 
      for(e=head2[x];e!=-1;e=edge2[e].next)
      {
        in[edge2[e].v]--;
        if(in[edge2[e].v]==0)
        {
          sum++;
          S.push(edge2[e].v); 
        } 
      } 
      if(sum>=2) {flag=false;return;} 
    } 
    flag=true; 
} 
void solve()
{
    int i; 
    for(i=1;i<=n;++i)
     if(!dfn[i]) tarjan(i); 
    rebuild(); 
    tuopu(); 
} 
int main()
{
     int t; 
     scanf("%d",&t);
     while(t--)  
     {
       init(); 
       solve(); 
       if(flag) printf("Yes\n");
       else printf("No\n"); 
     } 
     //system("pause"); 
     return 0;
}

