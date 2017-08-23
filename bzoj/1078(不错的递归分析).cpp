#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
struct data {int p,l,r,ans[205];}a[205]; 
int al[205],ar[205];
int dfs(int x)
{
    int i;
    if(x==-1)   return 0;
    int l=dfs(a[x].l),r=dfs(a[x].r);
    memcpy(al,a[a[x].l].ans,sizeof(al));
    memcpy(ar,a[a[x].r].ans,sizeof(ar));
    if(l==r)
    {
        int tot=0;
        a[x].ans[++tot]=a[x].p;
        for(i=1;i<=l;++i)   a[x].ans[++tot]=ar[i],a[x].ans[++tot]=al[i];
    } 
    else if(l==r+1)
    {
        int tot=0;
        a[x].ans[++tot]=a[x].p;a[x].ans[++tot]=al[1];
        for(i=1;i<=r;++i)   a[x].ans[++tot]=ar[i],a[x].ans[++tot]=al[i+1];
    }
    else if(l>r)
    {
        int tmp=l-r,tot=0;
        for(i=1;i<=tmp;++i) a[x].ans[++tot]=al[i];
        a[x].ans[++tot]=a[x].p;
        for(i=1;i<=r;++i)   a[x].ans[++tot]=ar[i],a[x].ans[++tot]=al[i+tmp];
    }
    else 
    {
        int tmp=r-l+1,tot=0; 
        for(i=1;i<=tmp;++i) a[x].ans[++tot]=ar[i];
        a[x].ans[++tot]=a[x].p;
        for(i=1;i<=l;++i)   a[x].ans[++tot]=al[i],a[x].ans[++tot]=ar[i+tmp];
    }
    return l+r+1;
}
int main()
{
    int i,x,n;
    scanf("%d",&n);
    for(i=0;i<=n;++i)   a[i].l=a[i].r=-1;
    for(i=1;i<=n;++i)
    {
        scanf("%d",&x);
        a[i].p=i;
        if(x<100)   a[x].l=i;
        else a[x-100].r=i;
    }
    int tmp=dfs(0);   
    for(i=1;i<=tmp;++i)   printf("%d ",a[0].ans[i]); 
    return 0;
}
