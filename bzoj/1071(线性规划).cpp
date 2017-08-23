#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int N=10005;
long long a,b,c;
int ans,hh[N],ww[N],wcnt[N];
struct data
{
    int h,w;
}p[N],q[N];
bool cmp(data x,data y)
{
    return a*x.h+b*x.w<a*y.h+b*y.w;
}
int main()
{
    int i,j,n;
    scanf("%d%lld%lld%lld",&n,&a,&b,&c);
    for(i=1;i<=n;++i)
    {
        scanf("%d%d",&p[i].h,&p[i].w);
        hh[i]=p[i].h,ww[i]=p[i].w;
    }
    sort(&p[1],&p[n+1],cmp);
    sort(&ww[1],&ww[n+1]),sort(&hh[1],&hh[n+1]);
    for(i=1;i<=n;++i)
    {
        if(i>1 && hh[i]==hh[i-1]) continue;
        int minh=hh[i];
        int cnt=0,now=1,tmp=c+a*minh;
        for(j=1;j<=n;++j)
        {
            if(j>1 && ww[j]==ww[j-1]) continue;
            int minw=ww[j];
            tmp+=b*minw;
            for(;now<=n;++now)
            {
                if(a*p[now].h+b*p[now].w>tmp)   break;
                if(p[now].h<minh || p[now].w<minw)  continue;
                ++wcnt[p[now].w],++cnt;   
            }
            if(j>=2)   cnt-=wcnt[ww[j-1]],wcnt[ww[j-1]]=0;
            ans=max(ans,cnt);
            tmp-=b*minw;
        }
    }
    printf("%d\n",ans);
    return 0;
} 
