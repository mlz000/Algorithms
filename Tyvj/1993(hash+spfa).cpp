#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath> 
#include<queue> 
using namespace std;
const int u=100010,w=5000010,MOD=99991; 
int to[w],edge[w],next[w],head[u],pos[u],go[u],h[u],b[10],f[u][10],d[u];
long long num[u],cost[u],a[u],p[10],temp;
int n,m,tot,i,j,k,l,x,y;
bool v[u]; 
queue<int> q; 
void hash(long long x,int y)
{
   int z=x%MOD; 
   num[++tot]=x;
   pos[tot]=y;
   go[tot]=h[z];
   h[z]=tot;//hash 
} 
int ask(long long x)
{
    int i; 
    int z=x%MOD;
    for(i=h[z];i;i=go[i])
     if(num[i]==x) return pos[i]; 
    return 0; 
} 
void add(int x,int y)
{
    to[++tot]=y;
    next[tot]=head[x];
    head[x]=tot; 
    for(;f[x][edge[tot]]==f[y][edge[tot]];edge[tot]++); 
     edge[tot]=cost[edge[tot]]; //最长前缀 
} 
void spfa()
{
   int i; 
   q.push(1); 
   d[1]=0; 
   while(!q.empty())
   {
      int x=q.front(); 
      q.pop(); 
      v[x]=false;
      for(i=head[x];i;i=next[i])
      {
        if(d[to[i]]>d[x]+edge[i])
        {
           d[to[i]]=d[x]+edge[i];
           if(!v[to[i]])
           {
              v[to[i]]=true; 
              q.push(to[i]); 
           } 
        } 
      } 
   } 
} 
int main()
{
    long long tmp; 
    scanf("%d",&n);
    for(i=0;i<10;++i)
     scanf("%I64d",&cost[i]);
    for(p[0]=i=1;i<=10;++i) p[i]=p[i-1]*10; 
    for(i=1;i<=n;++i)
    {
        scanf("%I64d",&a[i]);
        hash(a[i],i); 
        memset(b,0,sizeof(b)); 
        for(tmp=a[i],m=0;tmp;tmp=tmp/10) b[m++]=tmp%10;
        for(j=0;j<10;++j) f[i][j]=b[9-j];//第i个数第j位数字 
    } 
    tot=0; 
    for(i=1;i<=n;++i)
    {
       memset(b,0,sizeof(b)); 
       for(tmp=a[i],m=0;tmp;tmp=tmp/10) b[m++]=tmp%10;
       for(j=0;j<10;++j)
        for(k=0;k<10;++k)
        {
          if(b[j]!=b[k] && (l=ask(a[i]-b[j]*p[j]-b[k]*p[k]+b[j]*p[k]+b[k]*p[j]))) add(i,l);//交换2个位置的数字
          if(b[j]!=k && (l=ask(a[i]-b[j]*p[j]+k*p[j]))) add(i,l);   
        } 
    } 
    memset(d,0x3f,sizeof(d)); 
    spfa(); 
    if(d[n]==0x3f3f3f3f) {puts("-1"); return 0;}
    printf("%d\n",d[n]); 
  //  system("pause"); 
    return 0;
}
