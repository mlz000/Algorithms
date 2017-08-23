#include<cstdio>
#include<algorithm>
#include<iostream>
#include<climits>
#include<cmath>
using namespace std;
const int N=30005;
int n,m,tot,head[N],next[N*2],to[N*2],val[N],pre[N],dep[N],q[N],size[N],son[N],top[N],w[N],id[N];
int MAX[N*4],sum[N*4];
bool v[N];
char s[20];
#define lc x << 1
#define rc (lc) + 1
inline void add(int u,int v)
{
    to[++tot]=v;
    next[tot]=head[u];
    head[u]=tot;
}
void update(int x)
{
    MAX[x]=max(MAX[lc],MAX[rc]);
    sum[x]=sum[lc]+sum[rc]; 
}
void build(int x,int l,int r)
{
    if(l==r) 
    {
        MAX[x]=sum[x]=w[l];
        return ;    
    }
    int mid=(l+r)>>1;
    build(lc,l,mid);
    build(rc,mid+1,r);
    update(x);
}
void change(int x,int l,int r,int u,int val)
{
    if(l==r)
    {
        MAX[x]=sum[x]=val;
        return ;
    }
    int mid=(l+r)>>1;
    if(u<=mid)  change(lc,l,mid,u,val);
    else change(rc,mid+1,r,u,val);
    update(x);   
}
int qmax(int x,int l,int r,int ql,int qr)
{
    if(ql<=l && qr>=r)  return MAX[x];
    int mid=(l+r)>>1;
    int tmp1=INT_MIN;int tmp2=INT_MIN;
    if(ql<=mid) tmp1=qmax(lc,l,mid,ql,qr);
    if(qr>mid)  tmp2=qmax(rc,mid+1,r,ql,qr);
    return max(tmp1,tmp2);
}
int qsum(int x,int l,int r,int ql,int qr)
{
    if(ql<=l && qr>=r)  return sum[x];
    int mid=(l+r)>>1;
    int tmp1=0;int tmp2=0;
    if(ql<=mid) tmp1=qsum(lc,l,mid,ql,qr);
    if(qr>mid)  tmp2=qsum(rc,mid+1,r,ql,qr);
    return tmp1+tmp2;
}
inline int gmax(int a,int b)
{
    int tmp=INT_MIN;
    while(top[a]!=top[b])
    {
        if(dep[top[a]]<dep[top[b]]) swap(a,b);
        tmp=max(tmp,qmax(1,1,n,id[top[a]],id[a])); 
        a=pre[top[a]];
    }
    if(id[a]>id[b])   swap(a,b);
    tmp=max(tmp,qmax(1,1,n,id[a],id[b]));
    return tmp;
}
inline int gsum(int a,int b)
{
    int tmp=0;
    while(top[a]!=top[b])
    {
        if(dep[top[a]]<dep[top[b]]) swap(a,b);
        tmp+=qsum(1,1,n,id[top[a]],id[a]); 
        a=pre[top[a]];
    }
    if(id[a]>id[b])   swap(a,b);
    tmp+=qsum(1,1,n,id[a],id[b]);
    return tmp;
}
int main()
{
    scanf("%d",&n);
    int a,b;
    for(int i=1;i<n;++i)
    {
        scanf("%d%d",&a,&b);
        add(a,b);
        add(b,a);
    }
    for(int i=1;i<=n;++i)   scanf("%d",&val[i]);
    v[dep[1]=q[0]=1]=true;
    int r=0;tot=0;
    for(int l=0;l<=r;++l)
     for(int k=head[q[l]];k;k=next[k])
     {
        if(!v[to[k]])
        {
            v[to[k]]=true;
            dep[q[++r]=to[k]]=dep[q[l]]+1;
            pre[q[r]]=q[l];
        }
     }
    for(int i=r;i>=0;--i)
    {
        size[pre[q[i]]]+=++size[q[i]];
        if(size[q[i]]>size[son[pre[q[i]]]])
        son[pre[q[i]]]=q[i];
    } 
    for(int i=0;i<=r;++i)
    {
        if(!top[q[i]])  
         for(int k=q[i];k;k=son[k])
         {
            top[k]=q[i];
            w[id[k]=++tot]=val[k];
         }
    }
    build(1,1,n);
    scanf("%d",&m);
    for(int i=1;i<=m;++i)
    {
        scanf("%s%d%d",s,&a,&b);
        if(s[0]=='C')   change(1,1,n,id[a],b);
        else if(s[1]=='M')  printf("%d\n",gmax(a,b));
        else printf("%d\n",gsum(a,b));
    }
    return 0;
}
