#include<cstdio>//贪心 每到一个地点，让已经到站牛下车，下车计算。上完牛，超载时，先T下目的地远的，最后统计ans
#include<algorithm>
#include<iostream>
#include<cmath>
#include<queue> 
using namespace std;
const int N=50005; 
int hash[N],x[N],y[N];
struct data
{
    int l;
    int m;
    int p;
}a[N*2];
bool cmp(const data p,const data q)
{
    if(p.l!=q.l) return p.l<q.l;
    return p.m<q.m;
}
bool operator <(const data p,const data q)
{
    return p.l<q.l;
}
priority_queue<data> q;
int main()
{
    int i,j,k,n,c;
    scanf("%d%d%d",&k,&n,&c);
    int tot=0;
    for(i=1;i<=k;++i)    
    {
        int z;
        scanf("%d%d%d",&x[i],&y[i],&z);
        a[++tot].l=x[i];a[tot].m=z;a[tot].p=i;
        a[++tot].l=y[i];a[tot].m=-z;a[tot].p=i;
    }
    sort(&a[1],&a[tot+1],cmp);
    data p;p.l=p.p=0;;q.push(p);
    tot=c;int ans=0;j=1;
    for(i=1;i<=n;++i)
     for(;a[j].l==i;++j)
     {
      if(a[j].m>0)
      {
        int cnt=min(a[j].m,tot);
        while(1)
        {
            data p=q.top();
            if(p.l>y[a[j].p] && cnt>=c+hash[p.p])
            {
                c+=hash[p.p];
                hash[p.p]=0;
                q.pop();
            }
            else break;
        }
        data p=q.top();
        if(p.l>y[a[j].p])
        {
            if(cnt>c)
            {
                int cc=cnt-c;
                hash[p.p]-=cc;
                c+=cc;
            }
            a[j].l=y[a[j].p]; 
            q.push(a[j]);
            hash[a[j].p]=cnt;
            c-=cnt;
        }
        else 
        {
            cnt=min(cnt,c);
            if(cnt)
            {
                a[j].l=y[a[j].p];
                q.push(a[j]);
                hash[a[j].p]=cnt;
                c-=cnt;
            }
        }
      }
      else
      {
        int cnt=hash[a[j].p];
        c+=cnt;
        ans+=cnt;
        hash[a[j].p]=0;
      }
     }
    printf("%d",ans); 
    return 0;
}
